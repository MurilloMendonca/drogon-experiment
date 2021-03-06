#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",8888);
    drogon::HttpAppFramework::instance()
        .registerHandler("/list_para",
                        [=](const drogon::HttpRequestPtr &req,
                            std::function<void (const drogon::HttpResponsePtr &)> &&callback)
                        {
                            auto para=req->getParameters();
                            drogon::HttpViewData data;
                            data.insert("title","ListParameters");
                            data.insert("parameters",para);
                            auto resp=drogon::HttpResponse::newHttpViewResponse("ListParameters.csp",data);
                            callback(resp);
                        });
    //Load config file
    //drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
