#include <iostream>
#include <fstream>
#include <curlpp/cURLpp.hpp> //להתקין
#include <curlpp/Easy.hpp> //להתקין
#include <curlpp/Options.hpp>// להתקין

//תכתוב לי איזה סיפריות אני צריך להתקין וקישורים להתקנה שלהם לפי הקוד הבא?
int main() {
    // URL שבו נמצא קובץ המודל
    const std::string url = "URL_המלא_של_קובץ_המודל";

    // שם קובץ המודל במערכת הקבצים
    const std::string modelFileName = "model.pb";

    // פתח קובץ לכתיבה
    std::ofstream outFile(modelFileName, std::ios::binary);

    if (outFile.is_open()) {
        // הגדרות ה-request
        curlpp::Cleanup cleanup;
        curlpp::Easy request;
        request.setOpt(new curlpp::options::Url(url));
        request.setOpt(new curlpp::options::WriteStream(&outFile));

        // בצע את ה-request וכתוב לקובץ
        request.perform();

        // סגור את קובץ המודל
        outFile.close();
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    return 0;
}
