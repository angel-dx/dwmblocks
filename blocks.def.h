//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

	// CPU Usage
	// {" ", "grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$3+$4)} END {printf \"%.1f%%\", usage}'", 5, 1},

	// Memory Usage
  // { " ", "free -m | awk '/^Mem/ { printf(\"%d\", $3) }'", 5, 2 },
  { " ", "free -b | awk '/^Mem/ { printf(\"%.1f\", $3 / (1024*1024*1024)) }'", 5, 2 },

	// Disk Usage (root partition)
	// {" ", "df -h / | awk 'NR==2{printf \"%s/%s (%s)\", $3, $2, $5}'", 30, 3},

	// Network Interface Status (change wlan0/eth0 to your interface)
	// {" ", "ip route get 1.1.1.1 2>/dev/null | awk '/dev/ {print $5}' | head -1 || echo 'offline'", 10, 4},
  {"", "~/dotfiles/scripts/suckless/dm_net_status.sh", 10, 4},

	// Volume Level (ALSA)
	{" ", "pamixer --get-volume | awk '{printf \"%d%%\", $1}'", 1, 5},

	// Battery Status (for laptops - modify BAT0 if needed)
	// {" ", "cat /sys/class/power_supply/BAT*/capacity 2>/dev/null | head -1 | awk '{printf \"%d%%\", $1}' || echo 'AC'", 30, 6},

  { "", "~/dotfiles/scripts/suckless/battery_status.sh", 30, 6 },

	// Temperature (CPU thermal zone - adjust path if needed)
	// {"", "cat /sys/class/thermal/thermal_zone0/temp 2>/dev/null | awk '{printf \"%.0f°C\", $1/1000}' || echo 'N/A'", 10, 7},

	// Date and Time
	{" ", "date '+%a %m/%d %H:%M'", 5, 1},
};

static char delim[] = "  ";
static unsigned int delimLen = 5;

