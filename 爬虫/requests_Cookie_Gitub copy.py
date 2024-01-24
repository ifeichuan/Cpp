import requests

Cookies = '_octo=GH1.1.1642692638.1688285115; _device_id=da42bc5145ee7ead20a8f3de67e17eb9;user_session=MU8TTW5n3LoJJb9UF3GUYe4K_XHE4m2U8ctCL5fTcCblBLoW;__Host-user_session_same_site=MU8TTW5n3LoJJb9UF3GUYe4K_XHE4m2U8ctCL5fTcCblBLoW;logged_in=yes; dotcom_user=ifeichuan; preferred_color_mode=light;tz=Asia%2FShanghai; color_mode=%7B%22color_mode%22%3A%22auto%22%2C%22light_theme%22%3A%7B%22name%22%3A%22light%22%2C%22color_mode%22%3A%22light%22%7D%2C%22dark_theme%22%3A%7B%22name%22%3A%22dark%22%2C%22color_mode%22%3A%22dark%22%7D%7D; has_recent_activity=1; _gh_sess=EHC8M8WHIseFffibbs49bRTJnvX4g2PEAlB6XOH1wO3XkWCxbihvdxEw7QmUO4mhul0L6zFrbb0rgUxp4uxReXaMX86VNRXGrmsUyRrln%2FP1FSWSFFjaoAX%2F6OlukuLcusPb%2BvevG7yVR6zuMK2%2BmtyDirrL9ObLAJ%2FNR07jqcFtjRJ8rQyLv1uW8MA17fx%2B1lIU5gY5ehIoSW3mlE%2FFqbHq40TlOB6nuMlOL%2FAHbSKzmvG8ibfzKOAHmXnrLTxqmdHyFVvj7OdrYCDLyUC4N4j2gKt44feAvA5C0SJ9%2BBFpnMTPFQw2Or5m3nOpyIVz0tY3k9tInmN1IsMTt3m3pfCl%2FrBjN9XTrV9zdv2kEEH42OK9zZho7mREUYQGidS%2BifnYq374RljHwbU6eYXRzUhY4YU%3D--OJCOBfKPa1JcJ1iy--RLykqegnmkf8ZUvSREg%2F1Q%3D%3D'
jar = requests.cookies.RequestsCookieJar()
for cookie in Cookies.split(';'):
    key,value = cookie.split('=',1)
    jar.set(key,value)
r = requests.get('https://github.com',cookies = jar)
print(r.text)