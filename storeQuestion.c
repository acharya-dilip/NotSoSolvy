//
// Created by g4sker on 5/7/26.
//

#include "storeQuestion.h"
#include <stdio.h>

#include "maker.h"


//This Meager function was declared in another c file because I want to leave roomm foor improvement if possible csv integration and such
void storeQuestion() {

    FILE *file = fopen(fileInfo,"w");
    fwrite(&dataToStore,sizeof(dataToStore),1,file);
    fclose(file);

}

