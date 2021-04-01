//
//  oscSender.h
//  midiToOsc
//
//  Created by migizo on 2021/02/15.
//

#ifndef oscSender_h
#define oscSender_h

#include "oscpack/osc/OscOutboundPacketStream.h"
#include "oscpack/ip/UdpSocket.h"

#define IP_MTU_SIZE 9999
using namespace osc;
using namespace std;

class OscSender {
public:
    ~OscSender() {
        disconnect();
    }
    
    //------------------------------------------------------------------------
    void connect(const char *hostName, const int port, bool isBroadcast = true)
    {
        this->hostName = hostName;
        this->port = port;

        IpEndpointName host( hostName, port );
        char hostIpAddress[ IpEndpointName::ADDRESS_STRING_LENGTH ];
        host.AddressAsString( hostIpAddress );
        
        sendSocket = make_unique<UdpTransmitSocket>( host, isBroadcast);
        
    }
    
    //------------------------------------------------------------------------
    void disconnect() {
        clear();
    }
    
    //------------------------------------------------------------------------
    void send(const char* address, vector<float> values)
    {
        if (sendSocket == nullptr) return;
        
        char buffer[IP_MTU_SIZE];
        unique_ptr<osc::OutboundPacketStream> p = unique_ptr<OutboundPacketStream>(new OutboundPacketStream( buffer, IP_MTU_SIZE ));

        p->Clear();
        *p << BeginMessage( address );
        for (int i = 0; i < values.size(); i++) {
            *p << values[i];
        }
        *p << osc::EndMessage;
        sendSocket->Send( p->Data(), p->Size() );
    }
    
    //------------------------------------------------------------------------
    void clear()
    {
        // メモリ解放
        sendSocket.reset();
    }
    
    //------------------------------------------------------------------------
    void ping() {
       // send("/ping", vector<float>(1, 1));
    }
    
    const char* getHostName() {return this->hostName;}
    int getPort() {return this->port;}
private:
    unique_ptr<UdpTransmitSocket> sendSocket = nullptr;
    const char *hostName;
    int port;
};


#endif /* oscSender_h */
