#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box *box) {
    double volume, surfaceArea;

    volume = box->length * box->width * box->height;
    surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);

    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box *ptrBox;

    ptrBox = &myBox;

    // Accessing members of the structure using (*) asterisk and (.) dot operator
    (*ptrBox).length = 5.0;
    (*ptrBox).width = 3.0;
    (*ptrBox).height = 2.0;

    printf("Using (*) asterisk and (.) dot operator:\n");
    calculateVolumeAndSurfaceArea(ptrBox);

    // Accessing members of the structure using (->) arrow operator with pointer representation
    ptrBox->length = 4.0;
    ptrBox->width = 6.0;
    ptrBox->height = 3.0;

    printf("\nUsing (->) arrow operator with pointer representation:\n");
    calculateVolumeAndSurfaceArea(ptrBox);

    // Accessing members of the structure using (->) arrow operator with dot representation
    (*ptrBox).length = 2.0;
    (*ptrBox).width = 2.0;
    (*ptrBox).height = 2.0;

    printf("\nUsing (->) arrow operator with dot representation:\n");
    calculateVolumeAndSurfaceArea(ptrBox);

    return 0;
}