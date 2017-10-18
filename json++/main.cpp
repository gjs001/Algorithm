#include <iostream>
#include "JsonObject.h"
#include <cpprest\http_client.h>
#include <cpprest\json.h>

using namespace std;
using namespace web;


void PostTest(web::json::value json_v, std::wstring p_url) // 免贸 : 流立 累己
{
	web::http::client::http_client client(p_url);
	client.request(web::http::methods::POST, U("/"), json_v)
		.then([](const web::http::http_response& response) {
		return response.extract_json();
	})
		.then([&json_v](const pplx::task<web::json::value>& task) {
		try {
			json_v = task.get();
		}
		catch (const web::http::http_exception& e) {
			std::cout << "error " << e.what() << std::endl;
		}
	})
		.wait();

	std::wcout << json_v.serialize() << std::endl;
}


int main() // 流立 累己
{

	//makeJson();
	web::json::value J = GetJson(U("http://httpbin.org/123123"));
	wcout << J << endl;
	web::json::value A = J[U("headers")];
	cout << J.at(U("origin")).size() << endl;
	std::vector<std::wstring> Jkey{ U("args"), U("origin"), U("url") };
	std::vector<std::wstring> Akey{ U("Connection"), U("Host"), U("User-Agent") };
	CJsonObject O(J, Jkey);
	//O.SetJsonObject(A, Akey);
	O.SetJsonObject(A, Akey, U("headers"));
	O.Print();
	cout << endl;
	O.PostJsonObject(U("http://httpbin.org/post"));
	wcout << O.m_mCJsonList[U("headers")].GetString(U("Host"));
	//PostTest(O.GetJsonValue(), U("http://httpbin.org/post"));
//	int b = J[L"origin"].as_number().to_int32();
//	cout << b;

	
}