#include<stdio.h>
#include<stdint.h>

void afisare_pe_biti_uint64(uint64_t numar){
  uint64_t masca = 1L << 63;
  uint64_t masca_de_separare = 1L << 60;
  while(masca){
    printf((numar & masca) ? "1" : "0");
    if(masca & masca_de_separare){
      printf(" ");
      masca_de_separare >>= 4;
    }
    masca >>= 1;
  }
  printf("\n");
}

void mutare_biti_pe_rang_uint64(uint64_t numar){
  for(int8_t decalaj_octet = 8; decalaj_octet > 1; --decalaj_octet){
    uint64_t nibble_inferior = 0, nibble_superior = 0;
    uint64_t masca_nibble_inferior = 1L << (8 * decalaj_octet - 1), masca_nibble_superior = 1L << (8 * decalaj_octet - 2);
    //afisare_pe_biti_uint64(masca_nibble_inferior);
    //afisare_pe_biti_uint64(masca_nibble_superior);
    while(masca_nibble_inferior >> (8 * (decalaj_octet - 1))){
      nibble_inferior |= numar & masca_nibble_inferior;
      nibble_superior |= numar & masca_nibble_superior;
      masca_nibble_inferior >>= 2;
      masca_nibble_superior >>= 2;
    }
   
    //numar &= (0xF << 8 * decalaj_octet);
    //numar |= (nibble inferior | (nibble_superior >> 4));
    printf("\n");
    afisare_pe_biti_uint64(nibble_inferior);
    afisare_pe_biti_uint64(nibble_superior);
    printf("\n");
  }
}


int main(void){
  uint64_t numar;

  printf("numar = ");
  scanf("%ld", &numar);

  printf("Reprezentarea pe biti a numarului introdus: ");
  afisare_pe_biti_uint64(numar);

  mutare_biti_pe_rang_uint64(numar);
  
  return 0;
}
