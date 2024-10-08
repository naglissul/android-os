int fb = open("/dev/fb0", O_RDWR);
struct fb_var_screeninfo vinfo;
ioctl(fb, FBIOGET_VSCREENINFO, &vinfo);
long screensize = vinfo.yres_virtual * vinfo.xres_virtual * vinfo.bits_per_pixel / 8;

unsigned char *fbp = (unsigned char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);

// Set a white pixel at (100, 100)
int x = 100;
int y = 100;
long location = (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) + (y + vinfo.yoffset) * vinfo.line_length;
*((unsigned int*)(fbp + location)) = 0xFFFFFFFF;  // White pixel (ARGB)

