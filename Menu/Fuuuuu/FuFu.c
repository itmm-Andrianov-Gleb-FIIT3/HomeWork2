// конструктор меню
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
	/* ... */
}
// ввод массива
// входной параметр - размер - передаётся по указателю, так как меняется внутри
// функция возвращает массив с выделенной памятью и заполненный значениями пользователя
// подробнее почему так прочитать тут -
https://ru.stackoverflow.com/questions/608092/Выделение-дин-памяти-в-функциях
int* inputMass(int* size) {
	int* result_mass;
	/* ... */
	return result_mass;
}
// печать массива на экран
void printMass(int size, int* mass) { /* ... */ }
// поиск значения value в массиве mass
// возвращает индекс (позицию) найденного элемента в массиве
// если ничего не нашёл - возращает -1
int search(int value, int size, int* mass) { /* ... */ }
// бинарный поиск значения value в массиве mass
int binarySearch(int value, int size, int* mass) { /* ... */ }
// проверка отсортирован ли массив
// если массив отсортирован возвращает 1
// если массив не отсортирован возвращает 0
int checkSort(int size, int* mass)
// сортировка пузырьком с подсчётом перестановок и сравнений
void bubbleSort(int size, int* mass, int* swaps_count, int* comps_count) { /* ... */ }