object = build/app.o build/human_unit.o build/draw_submenu.o build/mylib.o\
build/view_humans.o build/read_record.o build/search_human_ui.o build/search_human.o build/read_human.o\
build/edit_record.o build/edit_human.o build/edit_human_ui.o build/get_human.o\
build/save_record.o build/create_human.o build/create_human_ui.o build/read_last_record.o build/main_menu.o\
build/product_unit.o\
build/view_products.o build/search_product_ui.o build/search_product.o build/read_product.o\
build/edit_product.o build/edit_product_ui.o build/get_product.o\
build/create_product.o build/create_product_ui.o\
build/confirm_invoice.o build/final_string.o build/get_customer_invoice.o\
build/get_product_invoice.o build/invoice_unit.o build/produce_string.o\
build/about.o

app: $(object)
	gcc -o build/app $(object)

build/app.o: app.c
	gcc -c app.c -o build/app.o

build/about.o: src/ui/about.c
	gcc -c src/ui/about.c -o build/about.o

build/main_menu.o: src/ui/main_menu.c
	gcc -c src/ui/main_menu.c -o build/main_menu.o

build/draw_submenu.o: src/ui/draw_submenu.c
	gcc -c src/ui/draw_submenu.c -o build/draw_submenu.o

build/mylib.o: include/mylib/myc.c
	gcc -c include/mylib/myc.c -o build/mylib.o

build/edit_record.o: src/core/edit_record.c
	gcc -c src/core/edit_record.c -o build/edit_record.o

build/save_record.o: src/core/save_record.c
	gcc -c src/core/save_record.c -o build/save_record.o

build/read_record.o: src/core/read_record.c
	gcc -c src/core/read_record.c -o build/read_record.o

build/read_last_record.o: src/core/read_last_record.c
	gcc -c src/core/read_last_record.c -o build/read_last_record.o

#human
build/human_unit.o: src/ui/human_unit.c
	gcc -c src/ui/human_unit.c -o build/human_unit.o

build/view_humans.o: src/ui/view_humans.c
	gcc -c src/ui/view_humans.c -o build/view_humans.o

build/read_human.o: src/business/read_human.c
	gcc -c src/business/read_human.c -o build/read_human.o

build/search_human_ui.o: src/ui/search_human_ui.c
	gcc -c src/ui/search_human_ui.c -o build/search_human_ui.o

build/search_human.o: src/business/search_human.c
	gcc -c src/business/search_human.c -o build/search_human.o

build/edit_human.o: src/business/edit_human.c
	gcc -c src/business/edit_human.c -o build/edit_human.o

build/edit_human_ui.o: src/ui/edit_human_ui.c
	gcc -c src/ui/edit_human_ui.c -o build/edit_human_ui.o

build/get_human.o: src/ui/get_human.c
	gcc -c src/ui/get_human.c -o build/get_human.o

build/create_human.o: src/business/create_human.c
	gcc -c src/business/create_human.c -o build/create_human.o

build/create_human_ui.o: src/ui/create_human_ui.c
	gcc -c src/ui/create_human_ui.c -o build/create_human_ui.o

#product
build/product_unit.o: src/ui/product/product_unit.c
	gcc -c src/ui/product/product_unit.c -o build/product_unit.o

build/view_products.o: src/ui/product/view_products.c
	gcc -c src/ui/product/view_products.c -o build/view_products.o

build/read_product.o: src/business/product/read_product.c
	gcc -c src/business/product/read_product.c -o build/read_product.o

build/search_product_ui.o: src/ui/product/search_product_ui.c
	gcc -c src/ui/product/search_product_ui.c -o build/search_product_ui.o

build/search_product.o: src/business/product/search_product.c
	gcc -c src/business/product/search_product.c -o build/search_product.o

build/edit_product.o: src/business/product/edit_product.c
	gcc -c src/business/product/edit_product.c -o build/edit_product.o

build/edit_product_ui.o: src/ui/product/edit_product_ui.c
	gcc -c src/ui/product/edit_product_ui.c -o build/edit_product_ui.o

build/get_product.o: src/ui/product/get_product.c
	gcc -c src/ui/product/get_product.c -o build/get_product.o

build/create_product.o: src/business/product/create_product.c
	gcc -c src/business/product/create_product.c -o build/create_product.o

build/create_product_ui.o: src/ui/product/create_product_ui.c
	gcc -c src/ui/product/create_product_ui.c -o build/create_product_ui.o

#factor
build/confirm_invoice.o: src/ui/invoice/confirm_invoice.c
	gcc -c src/ui/invoice/confirm_invoice.c -o build/confirm_invoice.o

build/final_string.o: src/ui/invoice/final_string.c
	gcc -c src/ui/invoice/final_string.c -o build/final_string.o

build/get_customer_invoice.o: src/ui/invoice/get_customer_invoice.c
	gcc -c src/ui/invoice/get_customer_invoice.c -o build/get_customer_invoice.o

build/get_product_invoice.o: src/ui/invoice/get_product_invoice.c
	gcc -c src/ui/invoice/get_product_invoice.c -o build/get_product_invoice.o

build/invoice_unit.o: src/ui/invoice/invoice_unit.c
	gcc -c src/ui/invoice/invoice_unit.c -o build/invoice_unit.o

build/produce_string.o: src/ui/invoice/produce_string.c
	gcc -c src/ui/invoice/produce_string.c -o build/produce_string.o

.PHONY: clean
clean:
	rm -f app $(object)
