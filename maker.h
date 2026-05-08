//
// Created by g4sker on 5/7/26.
//

#ifndef NOTSOSOLVY_MAKER_H
#define NOTSOSOLVY_MAKER_H

void openMaker();


typedef struct {

    char *question;

    struct optionToStore {
        char *A;
        char *B;
        char *C;
        char *D;
    }option;

    int answer;
    char *fileInfo;
}DataToStore;

extern DataToStore dataToStore;

#endif //NOTSOSOLVY_MAKER_H

