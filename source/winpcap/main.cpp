/*******************************************
 * des: test pcap_findalldevs
 * autor: zhongsx17hao@gmail.com 
 * time: 2017-03-01 21:42:00
********************************************/

#include <stdio.h>
#include <pcap/pcap.h>

int main()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;

	char errbuf[PCAP_ERRBUF_SIZE];
	/* Retrieve the device list */
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs:%s\n", errbuf);
		exit(1);
	}

	int i = 0;
	/* Print the list */
	for (d = alldevs; d; d = d->next)
	{
		printf("%d. %s", ++i, d->name);
		if (d->description)
		{
			printf(" (%s)\n", d->description);
		}
		else
		{
			printf(" (No description available)\n");
		}
	}


	if (i == 0)
	{
		printf("\n No interfaces found ! Make Sure WinPcap is installed.\n");
		return 0;
	}

	/* 不再需要设备列表，释放它 */
	pcap_freealldevs(alldevs);

	system("pause");

	return 0;
}