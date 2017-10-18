#include <iostream>
#include "cpprest\http_client.h"
#include "cpprest\json.h"
#include "cpprest\http_listener.h"
#include "JsonObject.h"
#include <vector>
#include <algorithm>

using namespace std;

wstring t_Token;

void PostJsonValue(web::json::value p_json, std::wstring p_url, wstring t_Token)
{
	web::http::client::http_client client(p_url);
	web::http::http_request request(web::http::methods::POST);
	request.headers().add(L"X-Auth-Token", t_Token);
	//request.headers().set_content_type(L"application/json");
	request.set_body(p_json);
	client.request(request)
	.then([](web::http::http_response response) {
		std::wostringstream ss;
		//ss << L"POST ----- Server returned returned status code " << response.status_code() << L"." << std::endl; // 로그확인용
		std::wcout << ss.str();
		
		return response.extract_json();
	})
	.then([&p_json](const pplx::task<web::json::value>& task) {
		try {
			p_json = task.get();
		}
		catch (const web::http::http_exception& e) {
			std::cout << "error " << e.what() << std::endl;
			
		}
	})
	.wait();


}

void delJsonValue(web::json::value p_json, std::wstring p_url, wstring t_Token)
{
	web::http::client::http_client client(p_url);
	web::http::http_request request(web::http::methods::DEL);
	request.headers().add(L"X-Auth-Token", t_Token);
	//request.headers().set_content_type(L"application/json");
	request.set_body(p_json);
	client.request(request)
		.then([](web::http::http_response response) {
		std::wostringstream ss;
		//ss << L"DELETE ----- Server returned returned status code " << response.status_code() << L"." << std::endl;
		std::wcout << ss.str();
		
		return response.extract_json();
	})
		.then([&p_json](const pplx::task<web::json::value>& task) {
		try {
			p_json = task.get();
		}
		catch (const web::http::http_exception& e) {
			std::cout << "error " << e.what() << std::endl;
		}
	})
		.wait();

	
}


std::wstring GetToken(std::wstring p_sUrl,
	std::wstring p_sQueryPath = U(""),
	std::vector<std::pair<std::wstring, std::wstring>>* p_pvQuery = nullptr) // 원본 출처 : http://v_lovepooh_v.blog.me/220756824564
{
	std::wstring sBody;
	web::http::client::http_client client(p_sUrl);
	web::uri_builder builder;
	if (!p_sQueryPath.empty())
	{
		builder.set_path(p_sQueryPath);
		if (!p_pvQuery->empty())
		{
			for (std::pair<std::wstring, std::wstring> pQuery : (*p_pvQuery))
			{
				builder.append_query(pQuery.first, pQuery.second);
			}
		}
	}

	pplx::task<void> requestTask = client.request(web::http::methods::GET, builder.to_string())
		.then([&](web::http::http_response response) {
		return response.extract_string();
	})
		.then([&](utility::string_t str) {
		sBody = str;
	});

	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
	return sBody;
}

std::wstring GetList(std::wstring p_sUrl, std::wstring t_Token,
	std::wstring p_sQueryPath = U(""),
	std::vector<std::pair<std::wstring, std::wstring>>* p_pvQuery = nullptr) // 원본 출처 : http://v_lovepooh_v.blog.me/220756824564 + 리퀘스트에 토큰 포함 수정
{
	std::wstring sBody;
	web::http::client::http_client client(p_sUrl);
	web::uri_builder builder;
	if (!p_sQueryPath.empty())
	{
		builder.set_path(p_sQueryPath);
		if (!p_pvQuery->empty())
		{
			for (std::pair<std::wstring, std::wstring> pQuery : (*p_pvQuery))
			{
				builder.append_query(pQuery.first, pQuery.second);
			}
		}
	}
	web::http::http_request request(web::http::methods::GET);
	request.headers().add(L"X-Auth-Token", t_Token);
	request.headers().set_content_type(L"application/json");
	pplx::task<void> requestTask = client.request(request)
		.then([&](web::http::http_response response) {
		return response.extract_string();
	})
		.then([&](utility::string_t str) {
		sBody = str;
	});

	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
	return sBody;
}

web::json::value docApi(wstring p_sUrl, wstring doc_Url) //document 리스트 받아오기
{
	wstring tar = p_sUrl + doc_Url;
	return GetJson(tar, t_Token);
}
web::json::value GetFeature(wstring p_sUrl, vector<wstring> addlist) // id값에 맞는 feature 받아오기
{
	int size = addlist.size();
	wstring tar = p_sUrl;
	for (int i=0;i<size;i++)
	{
		wstring now_id = addlist[i];
		tar.append(now_id);
		if(i!= size-1)tar.append(L",");
	}
	return GetJson(tar, t_Token);
}
wstring init()
{
	t_Token = GetToken(L"http://api.welcome.kakao.com/token/UvdG-KD6NN-qBTlrpgM82jn7KIMkJGJ2NW3v5"); // 제출용 토큰 받기
	std::wcout << t_Token;
	wstring doclist = GetList(U("http://api.welcome.kakao.com/seed"), t_Token); // 토큰에 맞는 문서 리스트 받기
	std::wcout << doclist;
	return doclist;
}

vector<wstring> wstr_split(wstring tar) // 문서 리스트 자르기
{
	vector<wstring> ret;
	int i = 0;
	int base = 0;
	while (tar[i])
	{
		if (tar[i] == '\n')
		{
			ret.push_back(tar.substr(base, i - base));
			base = i+1;
		}
		i++;
	}
	return ret;
}
wstring Getcategory(wstring uri) // 주소값에서 카테고리 값 파싱
{

	int i = 5;
	while (uri[i] != '/')
	{
		i++;
	}
	return uri.substr(5, i - 5);
}

void fuc(wstring doclist) 
{
	vector<wstring> v_doc = wstr_split(doclist);
	unordered_map<wstring, int> addmap;
	unordered_map<wstring, int> delmap;
	unordered_map<wstring, wstring> prevuri;
	vector<wstring> VS{ L"next_url",L"images" };
	vector<wstring> VF{ L"features" };
	vector<wstring> addlist;
	vector<web::json::value> dellist;
	while (1) // 문서리스트 무한 탐색
	{

		for (auto now_doc_uri : v_doc)  
		{
			if (prevuri[Getcategory(now_doc_uri)] != L"") // 해당 문서리스트에서 이전에 탐색한 url이 있는지 확인
			{
				now_doc_uri = prevuri[Getcategory(now_doc_uri)]; //탐색한 url부터 탐색 시작
			}
			else prevuri[Getcategory(now_doc_uri)] = now_doc_uri;

			web::json::value json_n_doc = docApi(L"http://api.welcome.kakao.com", now_doc_uri); // url에서 json 값 얻어오기
			
			//CJsonObject initj(json_n_doc, VS);
			web::json::array A = json_n_doc[L"images"].as_array(); // array형태로 저장되어있는 값 풀어서 vector에 저장
			vector<web::json::value> vjson_cmd_list;
			for (auto e : A)
				vjson_cmd_list.emplace_back(e);

			//vector<pair<wstring, wstring>> ftlist;


			while (1) // 해당 카테고리에서 현재 페이지에 데이터가 없을 때까지 탐색
			{
				
				for (auto json_cmd_now : vjson_cmd_list) //현재 페이지 탐색
				{
					if (addlist.size() >= 50)
					{
						web::json::value json_ft_add = GetFeature(L"http://api.welcome.kakao.com/image/feature?id=", addlist);
						
						/*CJsonObject ft_add(json_ft_add, VF);
						vector<web::json::value> json_ft_div = ft_add.m_mArrayList[L"features"];*/
					
						web::json::value ft_save;
	
						ft_save[L"data"] = json_ft_add[L"features"];
					
						PostJsonValue(ft_save, L"http://api.welcome.kakao.com/image/feature", t_Token);
						addlist.clear();
					}
					if (dellist.size() >= 50)
					{
						if (!addlist.empty()) // 추가리스트 먼저 서버 갱신 후 삭제 실시
						{
							web::json::value json_ft_add = GetFeature(L"http://api.welcome.kakao.com/image/feature?id=", addlist);
						
						/*	CJsonObject ft_add(json_ft_add, VF);
							vector<web::json::value> json_ft_div = ft_add.m_mArrayList[L"features"];*/

							web::json::value ft_save;

							ft_save[L"data"] = json_ft_add[L"features"];

							PostJsonValue(ft_save, L"http://api.welcome.kakao.com/image/feature", t_Token);
							addlist.clear();
						}
						web::json::value ft_del;
						ft_del[L"data"] = web::json::value::array(dellist);
						delJsonValue(ft_del, L"http://api.welcome.kakao.com/image/feature", t_Token);
						dellist.clear();
						
					}
					wstring id = json_cmd_now[L"id"].as_string();
					if (json_cmd_now[L"type"].as_string() == L"add" && addmap[id] == 0) // 중복처리를 위해서 상태 map에 1로 설정
					{
						addmap[id] = 1;
						addlist.emplace_back(id);
					}
					else if (json_cmd_now[L"type"].as_string() == L"del" && addmap[id] == 1) // 값이 없는데 삭제하는 걸 막기위해서 값이 save 되있는지 확인 후 delete
					{
						addmap[id] = 0;
						web::json::value tmp;
						tmp[L"id"] = web::json::value::string(id);
						dellist.emplace_back(tmp);
					}
				}
				if (json_n_doc[L"next_url"].as_string() != now_doc_uri) // 다음 페이지가 현재 페이지와 다를 경우만 다음 페이지로 이동
				{
					//std::wcout << L" now_check url = " << now_doc_uri << "\n"; // log 확인용
					now_doc_uri = json_n_doc[L"next_url"].as_string(); 
					
					json_n_doc = docApi(L"http://api.welcome.kakao.com", now_doc_uri);
	/*				CJsonObject O(json_n_doc, VS);
					json_cmd_list = O.m_mArrayList[L"images"];*/
					web::json::array A = json_n_doc[L"images"].as_array();
					vjson_cmd_list.clear();
					for (auto e : A)
						vjson_cmd_list.emplace_back(e);
					prevuri[Getcategory(now_doc_uri)] = now_doc_uri;
				}
				else
				{
					break;
				}
			}

	

		}
	}
}


int main()
{
	wstring doclist = init();
	fuc(doclist);
}
