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
float calculateDye(struct Dimension sizes, float paintConsumption) {
	// с помощью написанной ранее функции вычисл¤ем площадь поверхности
	int square = calculateSquare(sizes);
	// зна¤ расход и площадь вычисл¤ем сколько краски нужно
	float dye_needed = square * paintConsumption;
	return dye_needed;
}

float calculatePaintingCost(struct Dimension sizes, float paintConsumption, float
	paintWorkCost, float paintCost) {
	int dye_needed = calculateDye(sizes, paintConsumption);
	float PaintingCost = dye_needed * paintCost * paintWorkCost;
	std::cout << "Dye cost: " << PaintingCost << '\n';
	return PaintingCost;
}

float calculateCupboardCost(struct Dimension sizes, float cupboardCost) {
	int square = calculateSquare(sizes);
	float CupboardCost = (square * cupboardCost);
	std::cout << "Cupboard Cost: " << CupboardCost << '\n';
	return CupboardCost;
}
float calculateMass(struct Dimension sizes, float weight) {
	int V = calculateVolume(sizes);
	float Mass = weight * V;
	return Mass;
}

float calculateFL(struct Dimension sizes, float riseCost, float floorsCount, float deliveryCost, float weight) {
	int Mass = calculateMass(sizes, weight);
	int FL = (floorsCount - 1) * riseCost * Mass * deliveryCost;
	std::cout << "Delivery cost: " << FL << '\n';
	return FL;
}

float calculateCost(struct Dimension sizes, float cupboardCost, float paintConsumption, float paintWorkCost, float paintCost, float riseCost, float floorsCount, float deliveryCost, float weight) {
	int CupboardCost = calculateCupboardCost(sizes, cupboardCost);
	int FL = calculateFL(sizes, riseCost, floorsCount, deliveryCost, weight);
	int PaintingCost = calculatePaintingCost(sizes, paintConsumption, paintWorkCost, paintCost);
	float full_cost = CupboardCost + FL + PaintingCost;
	return full_cost;
}

int main() {
	// расход краски, стоимость работы по покраске, стоимость краски
	float paintConsumption = 0.8, paintWorkCost = 35.00, paintCost = 50.00;
	// стоимость материала шкафа за м2
	float cupboardCost = 650;
	float weight = 0.9;
	int floorsCount = 5;
	float deliveryCost = 500.00;
	float riseCost = 2.50;
	struct Dimension cupboard;
	std::cout << "CUPBOARD PARAMETERS\n";
	input(&cupboard);
	calculateSquare;
	calculateDye;
	float cost;
	cost = calculateCost(cupboard, cupboardCost, paintConsumption,
		paintCost, paintWorkCost, weight, floorsCount, riseCost, deliveryCost);

	int FL;
	int PaintingCost;
	int CupboardCost;

	std::cout << "Total cost: " << cost;
	return 0;
}