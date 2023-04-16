#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <fstream>

#pragma pack(push,1)
struct Header {
	char idlength;
	char colormaptype;
	char datatypecode;
	short colormaporigin;
	short colormaplength;
	char colormapdepth;
	short x_origin;
	short y_origin;
	short width;
	short height;
	char  bitsperpixel;
	char  imagedescriptor;
};
#pragma pack(pop)



struct Color {
	union {
		struct {
			unsigned char b, g, r, a;
		};
		unsigned char raw[4];
		unsigned int val;
	};
	int bytespp;

	Color() : val(0), bytespp(1) {
	}

	Color(unsigned char R, unsigned char G, unsigned char B, unsigned char A) : b(B), g(G), r(R), a(A), bytespp(4) {
	}

	Color(int v, int bpp) : val(v), bytespp(bpp) {
	}

	Color(const Color &c) : val(c.val), bytespp(c.bytespp) {
	}

	Color(const unsigned char *p, int bpp) : val(0), bytespp(bpp) {
		for (int i=0; i<bpp; i++) {
			raw[i] = p[i];
		}
	}

	Color & operator =(const Color &c) {
		if (this != &c) {
			bytespp = c.bytespp;
			val = c.val;
		}
		return *this;
	}
};


class Image {
protected:
	unsigned char* data;
	int width;
	int height;
	int bytespp;

	bool   load_rle_data(std::ifstream &in);
	bool unload_rle_data(std::ofstream &out);
public:
	enum Format {
		GRAYSCALE=1, RGB=3, RGBA=4
	};

	Image();
	Image(int w, int h, int bpp);
	Image(const Image &img);
	bool read_ima_file(const char *filename);
	bool write_ima_file(const char *filename, bool rle=true);
	bool flip_horizontally();
	bool flip_vertically();
	bool scale(int w, int h);
	Color get(int x, int y);
	bool set(int x, int y, Color c);
	~Image();
	Image & operator =(const Image &img);
	int get_width();
	int get_height();
	int get_bytespp();
	unsigned char *buffer();
	void clear();
};

#endif //__IMAGE_HPP__
