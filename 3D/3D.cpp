#include <iostream>

int main()
{
	int width = 120;
	int height = 30;
	float aspect = (float)width / height;
	float pixelaspect = 11.0f / 24.0f;

	char* screen = new char[width * height + 1];
	screen[width * height] = '\0';
	for (int t = 0; true; t++) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				float x = (float)i / width * 2.0f - 1.0f;
				float y = (float)j / height * 2.0f - 1.0f;
				x *= aspect * pixelaspect;
				x += sin(t * 0.1);
				//y += cos(t * 0.001);

				char pixel = ' ';
				if (x * x + y * y < 0.5) pixel = '@';
				screen[i + j * width] = pixel;
			}
		}
		system("cls");
		printf(screen);
	}
	getchar();
}
