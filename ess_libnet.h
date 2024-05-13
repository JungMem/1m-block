#include <stdint.h>

#define IPTYPE_TCP		0x06    /* TCP Protocol */

/*
 *  IPv4 header
 *  Internet Protocol, version 4
 *  Static header size: 20 bytes
 */
struct libnet_ipv4_hdr
{
    u_int8_t ver_len;
    u_int8_t dum0;
    u_int16_t total_length;   /* total length */
    u_int8_t dum1[5];
    u_int8_t ip_p;            /* protocol */
    u_int8_t dum2[2];
    
    u_int8_t ip_src[4];	      /* src ip */
    u_int8_t ip_dst[4];         /* dst ip */
};

/*
 *  TCP header
 *  Transmission Control Protocol
 *  Static header size: 20 bytes
 */
struct libnet_tcp_hdr
{
    u_int16_t th_sport;       /* source port */
    u_int16_t th_dport;       /* destination port */
    
    u_int32_t seq;
    u_int32_t ack;
    
    u_int8_t hlen;	/* header length */
    
    u_int8_t dum0[19];
};

