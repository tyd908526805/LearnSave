require('LuaXml')

xmlTable = {}

--[ fileName:文件名
--[ infoName:数据区域名称
function g_ReadConfig(fileName, infoName)
	--[ 根据传入文件名拼接文件名 加载xml文件
	local fileXml = tostring(fileName)..".xml"
	local file = xml.load(fileXml)
	--[ 根据传入需要读取的信息区域名
	--[ 找到需要读取的信息位置
	local info = file:find(tostring(infoName))
	if info ~= nil then
		--[ 获取读取出的xml数据行数
		local infoLength = table.getn(info)
		--[ 临时存储xml数据
		local infoTable = {}
		--[ 将xml数据写入临时表
		for i = 1, infoLength do
			--[ 需要要保证所有xml表所有数据唯一列名称为 ID
			local id = info[i].ID
			infoTable[id] = info[i]
		end
		--[ 将临时数据表写入全局表中
		xmlTable[fileName] = infoTable
	end
end

--[ fileName:文件名
--[ key:唯一ID索引值
--[ node:需要查找的目标名称
function g_GetConfigValue(fileName, key, node)
	--[ 根据传入需要查找的结点 拼接出查找使用字符串
	local head = node.."=\"(.-)\""
	--[ 根据文件名和唯一ID获取唯一数据行
	if xmlTable[tostring(fileName)] == nil then
		return nil
	end
	local data = tostring(xmlTable[tostring(fileName)][tostring(key)])
	--[ 拥有临时存储查找结果
	local result = ""
	_, _, result=string.find(data, head)
	return result
end
