#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
    struct Node *next; // Pointer to the next node
} node;
// Function to add a term to the polynomial
node* addTerm(node *head, int coeff, int exp) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;

    if (head == NULL || exp > head->exp) {
        temp->next = head;
        head = temp;
    } else {
        node *ptr = head;
        while (ptr->next != NULL && ptr->next->exp > exp) {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}
// Function to print the polynomial
void printPoly(node *head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    node *ptr = head;
    while (ptr != NULL) {
        if (ptr->coeff > 0 && ptr != head) {
            printf(" + ");
        } else if (ptr->coeff < 0) {
            printf(" - ");
            ptr->coeff = -ptr->coeff; // Convert to positive for display
        }
        printf("%dx^%d", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");
}
// Function to add two polynomials
node* addPolynomials(node *poly1, node *poly2) {
    node *result = NULL; // Resultant polynomial
    node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = addTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            result = addTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                result = addTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = addTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = addTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, exp;

    // Input for first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly1 = addTerm(poly1, coeff, exp);
    }

    // Input for second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly2 = addTerm(poly2, coeff, exp);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Print the polynomials and the result
    printf("First Polynomial: ");
    printPoly(poly1);
    printf("Second Polynomial: ");
    printPoly(poly2);
    printf("Resultant Polynomial: ");
    printPoly(result);

    // Free the allocated memory
    node *temp;
    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
