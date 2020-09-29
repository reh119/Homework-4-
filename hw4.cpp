#include <iostream>
#include "recursive.h"
#include "hw4.h"

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}
//****************************************************************************//
/*Psuedocode: if list is empty, return counter
else, counter = counter+list_rest(list); 
return SumHelper
*/
static int SumHelper (list_t list, int counter){
if (list_isEmpty(list)){ // if empty lidt, return current counter
  return counter; 
}
else 
  counter +=list_first(list);
  return SumHelper(list_rest(list),counter); 
}

//****************************************************************************//
/*Psuedocode: returns sumhelper, passes a list, and counter initiaized to zero
*/
int sum(list_t list){
  return SumHelper(list, 0);
}


//****************************************************************************//
/*Psuedocode: if list is empty, return current counter
else
counter = counter * list (except first element)
return ProductHelper 
*/
static int ProductHelper(list_t list, int counter){
if (list_isEmpty(list)){ // if empty lidt, return current counter
  return counter; 
}
else
counter = counter * list_first(list);
return ProductHelper(list_rest(list),counter); 

}
//****************************************************************************//
/*Psuedocode: if list is empty, return current counter
return product helper, initialize counter to 1
*/
int product(list_t list){

  return ProductHelper(list,1);
}
//list_first-returns first element of list (int)
//list_rest-returns list containing all but the first element(list_t)
//list_make - returns empty list 
//**************************************************************************//
static list_t ReverseHelper(list_t list, list_t reverse_list){
if (list_isEmpty(list)){
  return reverse_list; 
}
else {
reverse_list=list_make(list_first(list),reverse_list);
return ReverseHelper(list_rest(list),reverse_list);
}
}

list_t reverse(list_t list){ // type list_t func. just changes order of list
  list_t reverse_list = list_make();
  return ReverseHelper(list_t(list),reverse_list);

}
//****************************************************************//


static list_t AppendHelper(list_t first,list_t second,list_t new_list){
if (!list_isEmpty(first)){
  new_list=list_make(list_first(first),new_list);
  return AppendHelper(list_rest(first),second,new_list);
}

}



// first is list
// second is another list 

list_t append (list_t first, list_t second){

list_t new_list=list_make(); // returning an empty list into new_List

if (list_isEmpty(first)&&list_isEmpty(second)){

  return new_list;
}
if (list_isEmpty(first)){
  return second;
}
if (list_isEmpty(second)){
  return first;
}
return AppendHelper(first,second, new_list);





}

// list_first returns an int 
//list_rest goes down array/list 
//list_isempty checks to see if array is empty


