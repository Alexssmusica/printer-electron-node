#ifndef LINUX_PRINTER_H
#define LINUX_PRINTER_H
#include <cups/cups.h>
#include <cups/ppd.h>
#include "printer_interface.h"

class LinuxPrinter : public PrinterInterface {
private:
    std::string GetPrinterStatus(ipp_pstate_t state);

public:
    virtual PrinterInfo GetPrinterDetails(const std::string& printerName, bool isDefault = false) override;
    virtual std::vector<PrinterInfo> GetPrinters() override;
    virtual PrinterInfo GetSystemDefaultPrinter() override;
    virtual bool PrintDirect(const std::string& printerName, const std::vector<uint8_t>& data, const std::string& dataType) override;
    virtual PrinterInfo GetStatusPrinter(const std::string& printerName) override;
};

#endif 