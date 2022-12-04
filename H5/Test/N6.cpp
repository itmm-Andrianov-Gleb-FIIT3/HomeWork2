#include<iostream>
#include<string>

//                                              «Задание 6:
struct Dimension { // шкаф (описываетс¤ габаритами)
	int height;
	int depth;
	int width;
};
// ввод параметров шкафа
void input(struct Dimension* sizes) {
	std::cout << "Input height: ";
	std::cin >> (sizes->height);
	std::cout << "Input depth: ";
	std::cin >> (sizes->depth);
	std::cout << "Input width: ";
	std::cin >> (sizes->width);
}
// расчЄт поверхности шкафа
int calculateSquare(struct Dimension sizes) {
	int square_bok, square_updown, square_front, square;
	// 2 боковые крышки
	square_bok = 2 * sizes.height * sizes.depth;
	// верхн¤¤ и нижн¤¤ крышки
	square_updown = 2 * sizes.width * sizes.depth;
	// 1 передн¤¤ крышка
	square_front = sizes.height * sizes.width;
	square = square_bok + square_updown + square_front;
	return square;
}
// расчЄт объЄма шкафа
int calculateVolume(struct Dimension sizes) {
	int V = sizes.height * sizes.depth * sizes.width;
	return V;
}
// расчЄт сколько краски нужно на весь шкаф
// consumption Ц расход краски на м2
float calculateDye(struct Dimension sizes, float consumption) {
	// с помощью написанной ранее функции вычисл¤ем площадь поверхности
	int square = calculateSquare(sizes);
	// зна¤ расход и площадь вычисл¤ем сколько краски нужно
	float dye_needed = square * consumption;
	return dye_needed;
}

int main() {
	// расход краски, стоимость работы по покраске, стоимость краски
	float paintConsumption = 0.8, paintWorkCost = 35.00, paintCost = 50.00;
	// стоимость материала шкафа за м2
	float cupboardCost = 650;
	// вес кг/м2
	float weight = 0.9;
	// число этажей
	int floorsCount = 5;
	// float deliveryCost = 500.00;
	// float riseCost = 2.50;
	struct Dimension cupboard;
	std::cout << "CUPBOARD PARAMETERS\n";
	input(&cupboard);
	float cost;
	cost = calculateCost(cupboard, cupboardCost, paintConsumption,
		paintCost, paintWorkCost, weight, floorsCount, riseCost, deliveryCost);

	std::cout << "Total cost: " << cost;
	return 0;
}
