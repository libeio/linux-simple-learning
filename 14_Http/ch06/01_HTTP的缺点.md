
HTTP 无法保证通信数据的机密性，不可否认性和完整性。具体是指:
* 通信使用明文(不加密)，内容可能会被窃听
* 不验证通信方的身份，因此有可能遭遇伪装
* 无法证明报文的完整性，所以有可能已遭篡改


### 通信使用明文可能会被窃听

由于 HTTP 本身不具备加密的功能．所以也无法做到对通信整体(使用 HTTP 协议通信的请求和响应的内容)进行加密即，HTTP 报文使用明文(指未经过加密的报文)方式发送。

HTTP 协议中没有加密机制，但可以通过和SSL(Secure Socket Layer, 安全套接层)或TLS(Transpon Layer Security, 安全层传输协议)的组合使用，加密 HTTP 的通信内容。

用 SSL 建立安全通信线路之后，就可以在这条线路上进行 HTTP 通信了  。与 SSL 组合使用的 HTTP 被称为 HTTPS(HTTP Secure, 超文本传输安全协议)或 HTTP over SSL。


### 不验证通信方的身份就可能遭遇伪装

HTTP 协议中的请求和响应不会对通信方进行确认。这会产生如下隐患:
* 无法确定请求发送至目标的 Web 服务器是否是按真实意图返回响应的那台服务器。有可能是已伪装的 Web 服务器。
* 无法确定响应返回到的客户端是否是按真实意图接收响应的那个
客户端。有可能是已伪装的客户端。
* 无法确定正在通信的对方是否具备访问权限。因为某些 Web 服务器上保存着重要的信息，只想发给特定用户通信的权限。
* 无法判定请求是来自何方、出自谁手。
* 即便是无意义的请求也会照单全收。无法阻止海量请求下的 DoS 攻击。

SSL 不仅提供加密处理，而且还使用了一种被称为证书的手段，可用于确定通信方。证书由值得信任的第三方机构颁发，用以证明服务器和客户端是实际存在的。


### 无法证明报文完整性，可能已糟篡改

HTTP 协议无法证明通信的报文完整性。换句话说，没有任何办法确认，发出的请求/响应和接收到的请求/响应是前后相同的。

因为请求或响应在传输途中，很可能因为中间人攻击(MITM)而遭到拦截并篡改内容。

SSL 提供认证和加密处理及摘要功能。
