/*
*	https://www.hackerrank.com/contests/june-real-data/challenges/the-captcha-cracker
*/

#define HACKERRANK
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

#include <cassert>
#include <memory>
#include <vector>
namespace his
{

template<typename T> class Matrix;
typedef unsigned short ushort;

template<typename T>
class Matrix
{
public:
	Matrix()
	{}

	Matrix(size_t rows, size_t cols)
		:m_data(new std::vector<T>(rows * cols))
		,m_rows(rows), m_cols(cols), m_step(cols)
	{
		m_start = m_data->data();
	}

	void create(size_t rows, size_t cols)
	{
		m_rows = rows, m_cols = cols, m_step = cols;
		m_data.reset(new std::vector<T>(rows * cols));
		m_start = m_data->data();
	}
		
	void set(T t)
	{
		for (size_t y = 0; y < m_rows; ++y)
			for (size_t x = 0; x < m_cols; ++x)
				(*this)[y][x] = t;
	}
	Matrix crop(size_t top, size_t left, size_t rows, size_t cols) const
	{
		assert(top + rows <= m_rows && left + cols <= m_cols);
		Matrix<T> sub = *this;
		sub.m_start = m_start + m_step * top + left;
		sub.m_rows = rows;
		sub.m_cols = cols;
		return sub;
	}
			T *operator [](int y)			{ return m_start + m_step * y; }
	const	T *operator [](int y) const		{ return m_start + m_step * y; }

			T &operator ()(int y, int x)		{ return (*this)[y][x]; }
	const	T &operator ()(int y, int x) const	{ return (*this)[y][x]; }


			T *start()			{ return m_start; }
	const	T *start() const	{ return m_start; }

	int rows() const { return m_rows; }
	int cols() const { return m_cols; }
	int step() const { return m_step; }

protected:
	std::shared_ptr<std::vector<T>>	m_data;
	T *m_start;
	size_t m_rows, m_cols, m_step;
};


}

typedef unsigned char uchar;
static const char *result = "000110000011110001100110110000111100001111000011110000110110011000111100000110000001100000111000011110000001100000011000000110000001100000011000000110000111111000111100011001101100001100000011000001100000110000011000001100000110000011111111011111001100011000000011000001100001110000000110000000110000001111000110011111000000011000001110000111100011011001100110110001101111111100000110000001100000011011111110110000001100000011011100111001100000001100000011110000110110011000111100001111000110011011000010110000001101110011100110110000111100001101100110001111001111111100000011000000110000011000001100000110000011000001100000110000001100000000111100011001101100001101100110001111000110011011000011110000110110011000111100001111000110011011000011110000110110011100111011000000110100001101100110001111000001100000111100011001101100001111000011110000111111111111000011110000111100001111111100110001101100001111000110111111001100011011000011110000111100011011111100001111100110001111000001110000001100000011000000110000001100000101100011001111101111110011000110110000111100001111000011110000111100001111000011110001101111110011111110110000001100000011000000111111001100000011000000110000001100000011111110111111111100000011000000110000001111110011000000110000001100000011000000110000000011111001100011110000001100000011000000110001111100001111000011011000110011111011000011110000111100001111000011111111111100001111000011110000111100001111000011011111100001100000011000000110000001100000011000000110000001100000011000011111100001111000000110000001100000011000000110000001100000011001000110011011000011100011000011110001101100110011011000111100001111000011011000110011001100011011000011110000001100000011000000110000001100000011000000110000001100000011000000111111101100001111100111111111111101101111011011110110111100001111000011110000111100001111000011111000111111001111110011110110111101101111001111110001111100011111000011001111000110011011000011110000111100001111000011110000111100001101100110001111001111111011000011110000111100001111111110110000001100000011000000110000001100000000111100011001101100001111000011110000111100001111011011110011110110011000111101111111101100001111000011110000111111111011111000110011001100011011000011110000110111111011000011110000001100000001111110000000110000001100000011110000110111111011111111000110000001100000011000000110000001100000011000000110000001100000011000110000111100001111000011110000111100001111000011110000111100001101100110001111001100001111000011110000110110011001100110011001100011110000111100000110000001100011000011110000111100001111000011110110111101101111011011111111111110011111000011110000111100001101100110001111000001100000011000001111000110011011000011110000111100001111000011011001100011110000011000000110000001100000011000000110000001100011111110000001100000011000001100000110000011000001100000110000001100000011111110";
static const int thrd = 128;
class TheCaptchaCraker {
public:
	TheCaptchaCraker(vector<his::Matrix<float>> &features) : m_features(features) {}

	void Train() {
		int size = CharToId('Z') + 1;
		m_features.resize(size);
		for (auto &feature : m_features) {
			feature.create(10, 8);
			feature.set(0.f);
		}
		vector<int> counts(size, 0);

		for (int i = 0; i < 25; ++i) {
			char inputfilename[128], outputfilename[128];
			sprintf(inputfilename, "T:/Hackerrank/input/input%02d.txt", i);
			sprintf(outputfilename, "T:/Hackerrank/output/output%02d.txt", i);

			freopen(inputfilename, "r", stdin);
			vector<his::Matrix<uchar>> images = SliceInput(ReadInput());

			freopen(outputfilename, "r", stdin);
			char output[6]; scanf("%s", output);

			for (int j = 0; j < 5; ++j) {	
				char c = output[j];
				his::Matrix<uchar> &image = images[j];
				int id = CharToId(c);
				his::Matrix<float> &feature = m_features[id];
				for (int y = 0; y < image.rows(); ++y)
					for (int x = 0; x < image.cols(); ++x)
						feature(y, x) += image(y, x);
				counts[id]++;
			}
		}

		for (int i = 0; i < size; ++i) {
			his::Matrix<float> &feature = m_features[i];
			int count = counts[i];
			for (int y = 0; y < feature.rows(); ++y)
				for (int x = 0; x < feature.cols(); ++x)
					feature(y, x) /= count;
		}
	}
	void Save(ostream &os) {
		for (auto &feature : m_features) {
			for (int y = 0; y < feature.rows(); ++y) {
				for (int x = 0; x < feature.cols(); ++x) {
					os << (feature(y, x) < thrd) ? 0 : 1;
				}
			}
		}
	}
	void Load(istream &is) {
		int size = CharToId('Z') + 1;
		m_features.resize(size);
		for (auto &feature : m_features) {
			feature.create(10, 8);
			for (int y = 0; y < feature.rows(); ++y) {
				for (int x = 0; x < feature.cols(); ++x) {
					char c; is >> c;
					feature(y, x) = (c == '0') ? 255 : 0;
				}
			}
		}
	}
	int Dist(his::Matrix<uchar> &input, his::Matrix<float> &feature) {
		int dist = 0;
		for (int y = 0; y < input.rows(); ++y)
			for (int x = 0; x < input.cols(); ++x)
				if (feature(y, x) > thrd && input(y, x) < thrd)
					dist++;
				else if (feature(y, x) < thrd && input(y, x) > thrd)
					dist++;
		return dist;
	}
	char ImageToChar(his::Matrix<uchar> &image) {
		int size = CharToId('Z') + 1;
		int id = -1, min_dist = 10000;
		for (int i = 0; i < size; ++i) {
			int dist = Dist(image, m_features[i]);
			if (min_dist > dist) {
				min_dist = dist;
				id = i;
			}
		}
		if (id < 10)
			return id + '0';
		else
			return id - 10 + 'A';
	}
	void Test() {
		int errors = 0;
		for (int i = 0; i < 25; ++i) {
			char inputfilename[128], outputfilename[128];
			sprintf(inputfilename, "T:/Hackerrank/input/input%02d.txt", i);
			sprintf(outputfilename, "T:/Hackerrank/output/output%02d.txt", i);

			freopen(inputfilename, "r", stdin);
			vector<his::Matrix<uchar>> inputs = SliceInput(ReadInput());

			freopen(outputfilename, "r", stdin);
			char output[6]; scanf("%s", output);

			for (int j = 0; j < 5; ++j) {	
				char c = output[j];
				his::Matrix<uchar> &input = inputs[j];
				int id = CharToId(c);
				his::Matrix<float> &feature = m_features[id];
				char test = ImageToChar(input);
				if (test != c) {
					printf("%d %d:%c should be %c\n", i, j, test, c);
					errors++;
				}
			}
		}
		printf("%d errors!\n", errors);
	}
	
	his::Matrix<uchar> ReadInput() {
		int rows, cols;
		scanf("%d %d", &rows, &cols);
		his::Matrix<uchar> input(rows, cols);
		for (int y = 0; y < rows; ++y) {
			for (int x = 0; x < cols; ++x) {
				int r, g, b;
				scanf("%d,%d,%d", &r, &g, &b);
				input(y, x) = (r+g+b)/3;
			}
		}
		return input;
	}

	vector<his::Matrix<uchar>> SliceInput(his::Matrix<uchar> input) {
		vector<his::Matrix<uchar>> images;
		for (int i = 0; i < 5; ++i) {
			int top = 11, rows = 10;
			int left = 5 + i * 9, cols = 8;
			images.push_back(input.crop(top, left, rows, cols));
		}
		return images;
	}

	int CharToId(char c) {
		if (c >= '0' && c <= '9')
			return c - '0';
		else if (c >= 'A' && c <= 'Z')
			return c - 'A' + 10;
		else
			return -1;
	}

	vector<his::Matrix<float>> &m_features;
};

int main() {
	vector<his::Matrix<float>> features;
	TheCaptchaCraker cracker(features);
	//cracker.Train();
	//cracker.Save(fstream("train.txt", ios::out));
	stringstream ss(result);
	cracker.Load(ss);
	//cracker.Test();
	for (auto &input : cracker.SliceInput(cracker.ReadInput())) {
		cout << cracker.ImageToChar(input);
	}
	return 0;
}