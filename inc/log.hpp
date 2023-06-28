#pragma once
#include <fstream>
#include <iostream>

enum class LogLevel
{
	DEBUG,
	INFO,
	ERROR,
	WARN
};
class Log
{
private:
	static std::ofstream m_out;
	static LogLevel m_loglevel;
	static void write_log(const std::string& type_str, const std::string& log_msg);
		
	
public:
	Log();
	
	static void SetLogLevel(LogLevel loglevel);
	
	static void SetLogPath(const std::string& path);
	
	static void Write(LogLevel type, const std::string& msg);
	
	
	~Log();
	
};
