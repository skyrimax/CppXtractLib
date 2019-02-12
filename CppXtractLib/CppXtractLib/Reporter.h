#ifndef REPORTER_H
#define REPORTER_H


#include <string>


//! \brief 
class Reporter
{
public:
	Reporter() = default;
	virtual ~Reporter() = default;
	Reporter(const Reporter & transducer) = default;
	Reporter& operator=(const Reporter & transducer) = default;

	virtual std::string report() = 0;
};


#endif // REPORTER_H