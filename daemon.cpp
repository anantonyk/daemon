#include <iostream>
#include <thread>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <String.h>

using namespace std;

Config read_config();
void daemonize();
void* monitor_running_processes();
void* hdd_sdd_usage();

emun class Log_level {
	no_logs,
	production_logs,
	debug_logs,
	trace_logs
};

struct Config {
	Log_level log;
	bool is_flush_log_output;
	int period_time_to_call_threads;
	bool is_hdd_info_check;
	String hdd_info_filename;
	bool is_process_info_check;
	String process_info_filename;
}

int main(int argc, char* argv[]) {
	//check is conf file passed
	//global variable with conf filename
	Config conf;
	conf = read_config();
	daemonize();
	//create two threads (+check config)
	while(1) {
		
	}
}

void daemonize() {
	int pid;
	umask(0);
	chdir("/");
	
	pid = fork();
	if(pid < 0) {
		exit(1);
	}
	if(pid > 0) {
		exit(1);
	}
	setsid();
	pid = fork();
	if(pid < 0) {
		exit(1);
	}
	if(pid > 0) {
		exit(1);
	}
	return;
}

