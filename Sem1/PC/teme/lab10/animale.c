/*
  Să se implementeze o bază de date ce modelează animale. Animelele pot fi insecte, păsări, mamifere și pești.
  O insectă se caracterizează prin număr picioare și durata medie de viată în zile, o pasăre prin viteza de zbor și
  lungimea aripilor, un mamifer prin greutate, înălțime și tip de mancare (carnivor, ierbivor, omnivor) iar un pește
  prin greutate, adâncimea maximă de înnot și salinitatea apei (în procentaj). Să se definnească structurile de date
  necesare cât mai abstract posibil și cu amprenta de memorie minima. Se va defini un tablou de astfel de structuri
  și se vor implementa funcții de adaugare animal, stergere animal și printare animale.
*/

#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>


enum status_functie{
  ESEC,
  SUCCES
};

struct insecta{
  uint8_t numar_picioare;
  uint32_t durata_medie_de_viata_in_zile;
};

struct pasare{
  float viteza_de_zbor;
  float lungimea_aripilor;
};

struct mamifer{
  float greutate;
  float inaltime;
  enum tip_mamifer{
    carnivor,
    erbivor,
    omnivor
  } tip_mamifer;
};

struct peste{
  float greutate;
  float adancime_maxima_de_innot;
  float salinitatea_apei;
};

typedef struct{
  char* nume_animal;
  char* tip_animal;
  union{
    struct insecta animal_insecta;
    struct pasare animal_pasare;
    struct mamifer animal_mamifer;
    struct peste animal_peste;
  } caracteristici_animal;
} animal;

enum status_functie adaugare_animal(animal* colectie_animale, size_t* dimensiune_colectie_animale, animal animal_nou){
  *dimensiune_colectie_animale += sizeof(animal_nou);
  if( ( colectie_animale = realloc(colectie_animale, *dimensiune_colectie_animale) ) != NULL ){
    (colectie_animale + *dimensiune_colectie_animale - 1)->nume_animal = animal_nou.nume_animal;
    (colectie_animale + *dimensiune_colectie_animale - 1)->tip_animal = animal_nou.tip_animal;
    (colectie_animale + *dimensiune_colectie_animale - 1)->caracteristici_animal = animal_nou.caracteristici_animal;
    return SUCCES;
  } else{
    return ESEC;
  }
}

enum status_functie stergere_animal(animal* colectie_animale, size_t* dimensiune_colectie_animale, animal animal_nou){
  
}

int main(void){
  //animal *animale = NULL;
  
  return 0;
}
