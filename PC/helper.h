#include<stdio.h>
#include<stdint.h>

#define to_string(argument) # argument

void citire_numar(uint32_t* numar, char* nume_variabila){
  printf("%s = ", nume_variabila);
  scanf("%d", numar);
}

void afisare_binar_uint8(uint8_t numar){
  uint8_t masca = 1 << 7;
  uint8_t masca_de_separare = 1 << 3;

  while(masca != 0){
    printf(numar & masca ? "1" : "0");
    masca >>= 1;

    if(masca & masca_de_separare){
      printf(" ");
    }
  }
  printf("\n");
}

void afisare_binar_uint16(uint16_t numar){
  uint16_t masca = 1 << 15;
  uint16_t masca_de_separare = 1 << 11;

  while(masca != 0){
    printf(numar & masca ? "1" : "0");
    masca >>= 1;

    if(masca & masca_de_separare){
      printf(" ");
      masca_de_separare >>= 4;
    }
  }
  printf("\n");
}

void afisare_binar_uint32(uint32_t numar){
  uint32_t masca = 1 << 31;
  uint32_t masca_de_separare = 1 << 27;

  while(masca != 0){
    printf(numar & masca ? "1" : "0");
    masca >>= 1;

    if(masca & masca_de_separare){
      printf(" ");
      masca_de_separare >>= 4;
    }
  }
  printf("\n");
}

void setare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar |= 1 << pozitie;
}

void resetare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar &= ~(1 << pozitie);
}

void complementare_bit_uint8(uint8_t* numar, uint8_t pozitie){
  *numar ^= (1 << pozitie);
}

void stocare_char(char* container, uint8_t numar1, uint8_t numar2){
  *container |= numar1 << 4;
  *container |= numar2;
}

void setare_bit_uint16(uint16_t* numar, uint8_t pozitie){
  *numar |= 1 << pozitie;
}

void resetare_bit_uint16(uint16_t* numar, uint8_t pozitie){
  *numar &= ~(1 << pozitie);
}

void complementare_bit_uint16(int16_t* numar, uint8_t pozitie){
  *numar ^= (1 << pozitie);
}

uint8_t suma_biti_uint8(uint8_t numar, uint8_t biti){
  uint8_t suma = 0;
  
  uint8_t masca = 1;
  for(uint8_t i = 0; i < biti; ++i, masca <<= 1){
    suma += ((numar & masca) != 0);
  }

  return suma;
}

uint32_t inlocuire_byte(uint32_t numar_32_biti, uint8_t numar_8_biti, uint8_t pozitie_byte){
  uint16_t pozitie_bit = pozitie_byte * 8;
  return
    ( numar_32_biti & ~(0xFF << pozitie_bit) ) |
    ( numar_8_biti << pozitie_bit );
}

uint32_t rotire_la_dreapta(uint32_t numar, uint16_t pozitii){
  return
    ( numar << pozitii ) |
    ( ( numar & ( 0xFFFF << (32 - pozitii) ) ) >> (32 - pozitii) );
}

// 1 2 carry sum diff borrow
// 0 0     0   0    0      0
// 0 1     0   1    1      1
// 1 0     0   1    1      0
// 1 1     1   0    0      0

typedef enum operatie {
  scadere,
  adunare
} operatie;

uint16_t operatie_pe_biti(uint8_t numar1, uint8_t numar2, operatie cod_operatie){
  while(numar2 != 0){
    uint8_t carry;

    if(cod_operatie == scadere){
      carry = ~numar1 & numar2;
    } else {
      carry = numar1 & numar2;
    }

    numar1 = numar1 ^ numar2;

    numar2 = carry << 1;
  }
  
  return numar1;
}
