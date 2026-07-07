#include <stdio.h>
#include <stdlib.h>  // Add this for atoi()
#include "get_product_invoice.h"
#include "../../../src/ui/product/search_product_ui.h"
#include "../../../include/mylib/myc.h"
#include "../../../src/business/product/search_product.h"
#include "../../../src/business/product/read_product.h"
#include "../../../include/business/product.h"

int get_product_invoice(product* product1, int* quantity, int* price) {
    char* filename = "data/product.bin";
    char* name = "product";
    printf("name of product: \n");
    char buffer[6];
    
    int result = search_product_ui(filename);
    
    if (result == 1) {
        printf("\n please enter code of %s \n", name);
        char code[10];
        result = get_name_stdin(code, sizeof(code));
        
        int status; long int position;
        int result1 = search_product_by_code(filename, code, &position, &status);
        
        if (result1 == 2) {
            printf("the code not exist \n"); 
            return 0;
        }
        
        if (result1 == 1) {
            if (read_product(filename,product1, &status, position) != 1){
                printf("error in read_product function \n");
                printf("status is: %d \n",status);
                if (status==3) printf("error in fread function \n");
                return 0;
            }
        }
        
        printf("please price of product \n");
        result = get_name_stdin(buffer, sizeof(buffer));
        *price = atoi(buffer);

        printf("please quantity of product \n");
        result = get_name_stdin(buffer, sizeof(buffer));
        *quantity = atoi(buffer);
        
        return 1;  // Success}
    }
    return 0;
}  