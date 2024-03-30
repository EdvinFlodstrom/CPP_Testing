#pragma once

void InitialLog();
void SaveLogToBuffer(const std::string& message, std::ostringstream& buffer);
void LogBuffer(std::ostringstream& buffer);