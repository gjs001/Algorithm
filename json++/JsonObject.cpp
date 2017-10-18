#include "JsonObject.h"
//원본 출처 : http://devluna.blogspot.kr/2015/05/webjsonvalue-c-rest-sdk.html // http://devluna.blogspot.kr/2015/05/web-service-json-c-rest-sdk.html
//본인 수정 내용 : Json 추가 함수(SetJsonObject) 작성(2중 Json 추가 함수 오버로딩)
//				   Print() 함수 2중 Json 출력 지원
//                 PostJsonValue() 함수 추가
CJsonObject::CJsonObject()
{
}

CJsonObject::CJsonObject(web::json::value p_jValue, std::vector<std::wstring> p_vKeyList)
{
	if (!p_vKeyList.empty())
		m_vKeyList = p_vKeyList;

	if (p_jValue.is_array())
	{
		web::json::array A = p_jValue.as_array();
		for (auto v : A)
			m_vArrayList.emplace_back(v, p_vKeyList);
	}
	else if (p_jValue.is_object())
	{
		std::vector<web::json::value> V;

		for (auto sKey : p_vKeyList)
		{
			web::json::value v = p_jValue.at(sKey);
			if (v.is_string())
				m_mStrList.emplace(sKey, v.as_string());
			else if (v.is_integer())
				m_mIntList.emplace(sKey, v.as_integer());
			else if (v.is_double())
				m_mDblList.emplace(sKey, v.as_double());
			else if (v.is_boolean())
				m_mBoolList.emplace(sKey, v.as_bool());
			else
				m_mStrList.emplace(sKey, U(""));
		}
	}
}

void CJsonObject::Clear()
{
	m_mStrList.clear();
	m_mIntList.clear();
	m_mDblList.clear();
	m_mBoolList.clear();
	m_vArrayList.clear();
}

void CJsonObject::SetJsonObject(web::json::value p_jValue, std::vector<std::wstring> p_vKeyList) // 직접 작성
{
	if (!p_vKeyList.empty())
		m_vKeyList = p_vKeyList;

	if (p_jValue.is_array())
	{
		web::json::array A = p_jValue.as_array();
		for (auto v : A)
			m_vArrayList.emplace_back(v, p_vKeyList);
	}
	else if (p_jValue.is_object())
	{
		std::vector<web::json::value> V;
		for (auto sKey : p_vKeyList)
		{
			web::json::value v = p_jValue.at(sKey);
			if (v.is_string())
				m_mStrList.emplace(sKey, v.as_string());
			else if (v.is_integer())
				m_mIntList.emplace(sKey, v.as_integer());
			else if (v.is_double())
				m_mDblList.emplace(sKey, v.as_double());
			else if (v.is_boolean())
				m_mBoolList.emplace(sKey, v.as_bool());
		}
	}
}

void CJsonObject::SetJsonObject(web::json::value p_jValue, std::vector<std::wstring> p_vKeyList, std::wstring m_mkey) // 직접 작성
{
	if (!p_vKeyList.empty())
		m_vKeyList = p_vKeyList;

	if (p_jValue.is_object())
	{
		//std::vector<web::json::value> V;
		CJsonObject V(p_jValue, p_vKeyList);
		m_mCJsonList.emplace(m_mkey, V);
	}
}

web::json::value CJsonObject::GetJsonValue()
{
	web::json::value V;
	if (isArray())
	{
		std::vector<web::json::value> VJ;
		for (auto JO : m_vArrayList)
			VJ.emplace_back(JO.GetJsonValue());
		V = web::json::value::array(VJ);
	}
	else
	{
		for (auto PS : m_mStrList)
			V[PS.first] = web::json::value::string(PS.second);
		for (auto PI : m_mIntList)
			V[PI.first] = web::json::value::number(PI.second);
		for (auto PD : m_mDblList)
			V[PD.first] = web::json::value::number(PD.second);
		for (auto PB : m_mBoolList)
			V[PB.first] = web::json::value::boolean(PB.second);
		for (auto PJ : m_mCJsonList) // 추가 구문
			V[PJ.first] = PJ.second.GetJsonValue();
	}
	return V;
}


void CJsonObject::PostJsonObject(std::wstring p_url) // 출처 : 직접 작성
{
	web::json::value json_v = GetJsonValue();
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

void CJsonObject::Print()
{
	wprintf(U("%s"), GetJsonValue().serialize().c_str());
}

web::uri_builder GetBuilder(std::wstring p_sQueryPath,
	std::vector<std::pair<std::wstring, std::wstring>>* p_pvQuery) 
{
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

	return builder;
}


web::json::value GetJson(std::wstring p_sUrl)
{
	std::wstring p_sQueryPath = U("");
	std::vector<std::pair<std::wstring, std::wstring>>* p_pvQuery = nullptr;
	web::json::value vJson;
	web::http::client::http_client client(p_sUrl);
	web::uri_builder builder = GetBuilder(p_sQueryPath, p_pvQuery);

	pplx::task<void> requestTask = client.request(web::http::methods::GET, builder.to_string())
		.then([&](web::http::http_response response) {
		return response.extract_json();
	})
		.then([&](pplx::task<web::json::value> previousTask) {
		try
		{
			vJson = previousTask.get();
		}
		catch (const web::http::http_exception& e)
		{
			printf("Error exception:%s\n", e.what());
		}
	});
	if (vJson.is_object() == false) vJson = GetJson(p_sUrl);
	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
	return vJson;
}
