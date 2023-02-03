#include <stdio.h>

int viral_advertising(const int days);

int main() {

	int days;
	scanf("%d", &days);

	const int cumulative_likes = viral_advertising(days);
	printf("%d\n", cumulative_likes);

	return 0;
}

int viral_advertising(const int days) {
	int shared = 5, liked = 0, cumulative = 0;

	for (int i = 0; i < days; i++) {
		liked = shared / 2;
		cumulative += liked;
		shared = liked * 3;

		printf("%d\n", liked);
	}

	return liked;
}
