H.o : HouseholdLedger.h HouseholdLedger.c
	gcc -c $^ $@

H : main.c HouseholdLedger.o
	gcc -o $@ $^

clean :
	rm -.o H
