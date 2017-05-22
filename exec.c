#include <stdlib.h>
#include <string.h>
#include <nfc/nfc.h>

int CardTransmit(nfc_device*pnd,uint8_t*capdu,size_t capdulen,uint8_t*rapdu,size_t*rapdulen)
{int res;size_t szPos;if((res=nfc_initiator_transceive_bytes(pnd,capdu,capdulen,rapdu,*rapdulen,500))<0){return-1;}else{*rapdulen=(size_t)res;for(szPos=0;szPos<*rapdulen;szPos++){printf("%02x ",rapdu[szPos]);}
        printf("\n");return 0;}}
        int main(int argc, const char *argv[])
        {
            nfc_device * pnd;
            nfc_target nt;
            nfc_context * context;
            nfc_init( & context);
            if (context == NULL) {
                printf("Unable to init libnfc (malloc)\n");
                exit(EXIT_FAILURE);
            }
            const char * acLibnfcVersion = nfc_version();
            (void) argc;
            pnd = nfc_open(context, NULL);
            if (pnd == NULL) {
                printf("ERROR: %s", "Unable to open NFC device.");
                exit(EXIT_FAILURE);
            }
            if (nfc_initiator_init(pnd) < 0) {
                nfc_perror(pnd, "nfc_initiator_init");
                exit(EXIT_FAILURE);
            }
            const nfc_modulation nmMifare = {
                .nmt = NMT_ISO14443A,
                .nbr = NBR_106,
            };
            while (nfc_initiator_select_passive_target(pnd, nmMifare, NULL, 0, & nt) <= 0);
            uint8_t capdu[264];
            size_t capdulen;
            uint8_t rapdu[264];
            size_t rapdulen;
            int k = 0;
            switch(*argv[1]){
                case '1':
                k=20;memcpy(capdu,"\x00\xA4\x04\x00\x0E\x32\x50\x41\x59\x2E\x53\x59\x53\x2E\x44\x44\x46\x30\x31\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(szPos>30&&(rapdu[szPos]!=0x6e||rapdu[szPos]!=0x9f)){if(rapdu[szPos]==0x6e||rapdu[szPos]==0x9f)
                break;}}
                printf("\n");
                break;
                case 'm':
                k=13;memcpy(capdu,"\x00\xa4\x04\x00\x07\xa0\x00\x00\x00\x04\x10\x10\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(szPos>30&&(rapdu[szPos]!=0x6e||rapdu[szPos]!=0x9f)){if(rapdu[szPos]==0x6e||rapdu[szPos]==0x9f)
                break;}}
                printf("\n");
                k=5;memcpy(capdu,"\x00\xb2\x01\x0c\x00\x52",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(rapdu[szPos]==0x56&&rapdu[szPos+2]==0x42){break;}}
                printf("\n");
                k=5;memcpy(capdu,"\x80\xCA\x9f\x17\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                k=5;memcpy(capdu,"\x80\xCA\x9f\x4f\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x01\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x02\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x03\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x04\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x05\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x06\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x07\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x08\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x09\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x0A\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                break;
                case 'v':
                k=12;memcpy(capdu,"\x00\xa4\x04\x00\x07\xa0\x00\x00\x00\x03\x10\x10",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(szPos>30&&(rapdu[szPos]!=0x6e||rapdu[szPos]!=0x9f)){if(rapdu[szPos]==0x6e||rapdu[szPos]==0x9f)
                break;}}
                printf("\n");
                k=4;memcpy(capdu,"\x00\xb2\x01\x0c\x00\x52",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(rapdu[szPos]==0x56&&rapdu[szPos+2]==0x42){break;}}
                printf("\n");
                k=5;memcpy(capdu,"\x80\xCA\x9f\x17\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                k=5;memcpy(capdu,"\x80\xCA\x9f\x4f\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x01\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x02\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x03\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x04\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x05\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x06\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x07\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);printf("\n");k=5;memcpy(capdu,"\x00\xB2\x08\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x09\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);k=5;memcpy(capdu,"\x00\xB2\x0A\x5C\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                break;
                case 'i':
                k=12;memcpy(capdu,"\x00\xa4\x04\x00\x07\xa0\x00\x00\x00\x03\x10\x10",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(szPos>30&&(rapdu[szPos]!=0x6e||rapdu[szPos]!=0x9f)){if(rapdu[szPos]==0x6e||rapdu[szPos]==0x9f)
                break;}}
                printf("\n");
                k=5;memcpy(capdu,"\x80\xCA\x9f\x36\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                break;
                case 'a':
                k=13;memcpy(capdu,"\x00\xa4\x04\x00\x07\xa0\x00\x00\x00\x04\x10\x10\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);for(int szPos=0;szPos<rapdulen;szPos++){if(szPos>30&&(rapdu[szPos]!=0x6e||rapdu[szPos]!=0x9f)){if(rapdu[szPos]==0x6e||rapdu[szPos]==0x9f)
                break;}}
                printf("\n");
                k=5;memcpy(capdu,"\x80\xCA\x9f\x36\x00",k);capdulen=k;rapdulen=sizeof(rapdu);if(CardTransmit(pnd,capdu,capdulen,rapdu,&rapdulen)<0)
                exit(EXIT_FAILURE);if(rapdulen<2||rapdu[rapdulen-2]!=0x90||rapdu[rapdulen-1]!=0x00)
                exit(EXIT_FAILURE);
                break;
            }
            nfc_close(pnd);
            nfc_exit(context);
            exit(EXIT_SUCCESS);
        }
