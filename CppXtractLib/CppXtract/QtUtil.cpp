#include "stdafx.h"

#include "QtUtil.h"

QString complyFileName(const QString & completeFileName, size_t maxLength)
{
	QString formatedFileName;
	QString leftFileName;
	QString rightFileName;

	int index = completeFileName.lastIndexOf("/");
	int length = completeFileName.length();

	if (length <= maxLength)
	{
		formatedFileName = completeFileName;
	}
	else if (length-index > maxLength)
	{
		leftFileName = completeFileName.left((maxLength - 3) / 2);
		rightFileName = completeFileName.right((maxLength - 3) / 2);
	}
	else if (length-index > (maxLength - 3) / 2)
	{
		rightFileName = completeFileName.mid(index);
		leftFileName = completeFileName.left(maxLength-rightFileName.length()-3);
	}
	else
	{
		leftFileName = completeFileName.left((maxLength - 3) / 2);
		rightFileName = completeFileName.right((maxLength - 3) / 2);
	}
		
	formatedFileName = leftFileName + "..." + rightFileName;

	return formatedFileName;
}