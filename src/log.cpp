#include "../inc/log.hpp"


void Log::write_log(const std::string& type_str, const std::string& log_msg) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", ltm);
	m_out << "[" << buffer << "] " << "[" << type_str << "] " << log_msg << std::endl;
}
Log::Log()
{
	std::cout << "constr";
}
void Log::SetLogLevel(LogLevel loglevel)
{
	m_loglevel = loglevel;
}
void Log::SetLogPath(const std::string& path)
{
	m_out.open(path);
}
void Log::Write(LogLevel type, const std::string& msg)
{
	switch (type)
	{
	case LogLevel::DEBUG:
#ifdef _DEBUG
		write_log("DEB", msg);
#endif // _DEBUG

		break;
	case LogLevel::INFO:
		write_log("INFO", msg);
		break;
	case LogLevel::ERROR:
		write_log("ERR", msg);
		break;
	case LogLevel::WARN:
		write_log("WARN", msg);
		break;
	default:
		break;
	}
}
Log::~Log()
{
	std::cout << "destr";
}
std::ofstream Log::m_out;
LogLevel Log::m_loglevel;
