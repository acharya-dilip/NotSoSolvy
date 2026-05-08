//
// Created by g4sker on 5/7/26.
//

#ifndef NOTSOSOLVY_MAKER_H
#define NOTSOSOLVY_MAKER_H

void openMaker();


typedef struct {

    char question[256];

    struct optionToStore {
        char A[128];
        char B[128];
        char C[128];
        char D[128];
    }option;

    int answer;
}DataToStore;
extern char fileInfo[256];
extern DataToStore dataToStore;

#endif //NOTSOSOLVY_MAKER_H

