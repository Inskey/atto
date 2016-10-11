// compile with C++ 14 for binary literals

using namespace std;


enum class color : uint8_t
{
        BLACK   = 0b000,
        RED     = 0b001,
        GREEN   = 0b010,
	YELLOW  = 0b011,
	BLUE    = 0b100,
	MAGENTA = 0b101,
	CYAN    = 0b110,
	WHITE   = 0b111
}

struct style
{
	color fg, bg;
	bool bright;
};

class colors
{
	public:
		static void init_colors();
		static void set_current_style(style s);
}
