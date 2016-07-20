#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct _S_PACKET_REQ_GETPOS {
	unsigned short header;
	unsigned short req_type;
	unsigned int m_nIndex;

} _S_PACKET_REQ_GETPOS;

typedef struct _S_PACKET_RCV_POS {
	unsigned short header;
	unsigned short m_nIndex;
	float m_fxpos;
	float m_fypos;

} _S_PACKET_RCV_POS;

int main()
{
	int socket_desc;
	struct sockaddr_in server;
	static char read_buffer[2000];
	
	_S_PACKET_REQ_GETPOS testPacket = {1004,201,0};
	
	printf("%d,%d \r\n",testPacket.header,testPacket.req_type);

	socket_desc = socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1)
	{
			puts("err create socket");	
	}	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	if(connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}
	if(send(socket_desc,&testPacket,sizeof(testPacket),0) < 0) {
		puts("send failed");
	}
	puts("send success");

	if(recv(socket_desc,read_buffer,2000,0) < 0) {
		puts("recv fauled");
	}
	
	_S_PACKET_RCV_POS *recv_pos = (_S_PACKET_RCV_POS *)read_buffer;

	printf("%d, %d ,%f, %f \r\n",recv_pos->header,recv_pos->m_nIndex, recv_pos->m_fxpos,recv_pos->m_fypos);

	return 0;
}
