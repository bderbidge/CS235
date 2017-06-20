//
//  QS.cpp
//  Quicksort
//
//  Created by Brandon Derbidge on 11/26/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include "QS.h"


/*
 * sortAll()
 *
 * Sorts elements of the array.  After this function is called, every
 * element in the array is less than or equal its successor.
 *
 * Does nothing if the array is empty.
 */
void QS::quick_sort(int first, int last)
{
    if(last - first == 1)
    {
        medianOfThree(first,last);
    }
    else if( last - first == 2 )
    {
        medianOfThree(first, last);
    }
    else if(last - first > 1)
    {
        int pivot = medianOfThree(first, last);
        
        pivot = partition(first, last, pivot);
        
        quick_sort(first, pivot-1);
        
        quick_sort(pivot+1, last);
        
        
    }
}

void QS::sortAll(){
    
    if(count > 0){
      cout << "THis is the stuff " << *quicksort << "   " << quicksort[count -1] << endl;
      quick_sort(0, count-1);
    }
}

/*
 * medianOfThree()
 *
 * The median of three pivot selection has two parts:
 *
 * 1) Calculates the middle index by averaging the given left and right indices:
 *
 * middle = (left + right)/2
 *
 * 2) Then bubble-sorts the values at the left, middle, and right indices.
 *
 * After this method is called, data[left] <= data[middle] <= data[right].
 * The middle index will be returned.
 *
 * Returns -1 if the array is empty, if either of the given integers
 * is out of bounds, or if the left index is not less than the right
 * index.
 *
 * @param left
 * 		the left boundary for the subarray from which to find a pivot
 * @param right
 * 		the right boundary for the subarray from which to find a pivot
 * @return
 *		the index of the pivot (middle index); -1 if provided with invalid input
 */
int QS::medianOfThree(int left, int right){
    
    if( count == 0)
        return -1;
    if(left < 0 || left > count || left >= size || left> right)
        return -1;
    if(right < 0 || right > count || right >= size || left == right) return -1;
    
    int middle = (left + right)/2;
    
    if(quicksort[left] > quicksort[middle])
        swap(quicksort[left], quicksort[middle]);
    
    if(quicksort[middle] > quicksort[right])
        swap(quicksort[middle], quicksort[right]);
    
    if(quicksort[left] > quicksort[middle])
        swap(quicksort[left], quicksort[middle]);
    
    return middle;
}

/*
 * Partitions a subarray around a pivot value selected according to
 * median-of-three pivot selection.
 *
 * The values which are smaller than the pivot should be placed to the left
 * of the pivot; the values which are larger than the pivot should be placed
 * to the right of the pivot.
 *
 * Returns -1 if the array is null, if either of the given integers is out of
 * bounds, or if the first integer is not less than the second integer, or if the
 * pivot is not between the two boundaries.
 *
 * @param left
 * 		the left boundary for the subarray to partition
 * @param right
 * 		the right boundary for the subarray to partition
 * @param pivotIndex
 * 		the index of the pivot in the subarray
 * @return
 *		the pivot's ending index after the partition completes; -1 if
 * 		provided with bad input
 */
int QS::partition(int left, int right, int pivotIndex){
    
    if( count == 0) return -1;
    if(left < 0 || left > count || left >= size || left> right)
        return -1;
    if(right < 0 || right > count || right >= size || left == right)
        return -1;
    if(pivotIndex > right || pivotIndex < left || pivotIndex == right || pivotIndex == left)
        return -1;
    
    int up = left + 1;
    int down = right;
   // cout << " Left " << left << "  Right " << right << endl;
   // cout << "Before " <<  quicksort[left] << endl;
    
    swap(quicksort[left], quicksort[pivotIndex]);
   
    
    cout << "After " <<  quicksort[left] << endl;
    
    do{
        
        //cout << getArray() << endl;
        
        while ((quicksort[left] > quicksort[up] || quicksort[left] == quicksort[up] ) && !(up > right -1)) {
            up++;
            //cout << "  while  1" << "   " << quicksort[up] <<endl;
        }
        //if(quicksort[left] == quicksort[up])
          // up++;
        
        while (quicksort[down] > quicksort[left] && !(down< left + 1)) {
            --down;
           // cout << " while 2  " ;
         //   cout << quicksort[down] << "     " << quicksort[left] << endl;
        }
        
       // if(quicksort[up] == quicksort[down]){
         //   up++;
        //}
        
        if(quicksort[up] > quicksort[down])
        {
            if(down < up)
                break;
            
            else
           swap(quicksort[up], quicksort[down]);
        }
        
       // cout << " while 3 " << endl;
        
    }while(down > up) ;
    
    swap(quicksort[left], quicksort[down]);
    
    return down;
}

/*
 * Produces a comma delimited string representation of the array. For example: if my array
 * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
 * with no trailing comma.  The number of cells included equals the number of values added.
 * Do not include the entire array if the array has yet to be filled.
 *
 * Returns an empty string, if the array is NULL or empty.
 *
 * @return
 *		the string representation of the current array
 */
string QS::getArray(){
    
    string array =  "";
    ostringstream arraynum;
    
    if(quicksort == NULL || count == 0) return array;
    
    for(int i = 0; i < count; i++)
    {
        
        if(i == count - 1 )
        {
            arraynum << quicksort[i];
            
            return arraynum.str();
        }
        else{
            
            arraynum << quicksort[i] << ",";
            
        }
    }
    
    
    return arraynum.str();
}

/*
 * Returns the number of elements which have been added to the array.
 */
int QS::getSize(){
    
    return count;
}

/*
 * Adds the given value to the end of the array starting at index 0.
 * For example, the first time addToArray is called,
 * the give value should be found at index 0.
 * 2nd time, value should be found at index 1.
 * 3rd, index 2, etc up to its max capacity.
 *
 * If the array is filled, do nothing.
 */
void QS::addToArray(int value){
    
    if(count < this->size && this->size != 0){
        quicksort[count] = value;
        count++;
    }
}

/*
 * Dynamically allocates an array with the given capacity.
 * If a previous array had been allocated, delete the previous array.
 * Returns false if the given capacity is non-positive, true otherwise.
 *
 * @param
 *		size of array
 * @return
 *		true if the array was created, false otherwise
 */
bool QS::createArray(int capacity){
    
    if(capacity < 0 || capacity == 0) return false;
    
    count = 0;
    
    if(quicksort != NULL)
    {
        
        delete[] quicksort;
        quicksort = new int[capacity];
        this->size = capacity;
        return true;
    }
    quicksort = new int [capacity];
    this->size = capacity;
    return true;
}

/*
 * Resets the array to an empty or NULL state.
 */
void QS::clear(){
    
    delete[] quicksort;
    quicksort = NULL;
    count = 0;
    
}



