// #include <stdlib.h>
// #include <stdio.h>

// int* sort_array(int *array, int size)
// {
//     int *sorted = malloc(size * sizeof(int));
//     int i, j, temp;

//     i = 0;
//     while (i < size)
//     {
//         sorted[i] = array[i];
//         i++;
//     }

//     i = 0;
//     while (i < size)
//     {
//         j = 0;
//         while (j < size - i - 1)
//         {
//             if (sorted[j] > sorted[j + 1])
//             {
//                 temp = sorted[j];
//                 sorted[j] = sorted[j + 1];
//                 sorted[j + 1] = temp;
//             }
//             j++;
//         }
//         i++;
//     }

//     return sorted;
// }

// int main(void)
// {
//     int array[] = {6, 2, 1, 4, 5};
//     int size = sizeof(array) / sizeof(array[0]);
//     int *new_array;
//     int i;

//     new_array = sort_array(array, size);

//     i = 0;
//     while (i < size)
//     {
//         printf("%d ", new_array[i]);
//         i++;
//     }

//     free(new_array);
// 	return 0;
// }
