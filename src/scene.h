#include <cv.h>

class Scene {
	private:
		IplImage *rgb;
		IplImage *depth;
	public:
		Scene();
		void fetchImage();
		void build();
};
