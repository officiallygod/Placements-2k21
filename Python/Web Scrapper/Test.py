import requests
import time
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

url = 'https://in.ixl.com/maths/class-vii'
temp = requests.get(url)
soup = BeautifulSoup(temp.content, 'lxml')

li=[]
another = []
for i in soup.find_all('span',class_="skill-tree-skill-name"):
    li.append(i.text)
    
for i in soup.find_all('a',class_="skill-tree-skill-link"):
    another.append(i['href'])

driver = webdriver.Firefox()
    
res = li[95:103]
res1 = another[95:103]
anss = []
for i in range(len(res)):
    if i == 3 or i == 2:
        continue
    # print(f" Question: {res[i].strip()}")
    url1 = 'https://in.ixl.com/' + res1[i]
    driver.get(url1)
    time.sleep(5)
    sbox = driver.find_element_by_class_name("fillIn")
    sbox.send_keys('10')
    sbox.send_keys(Keys.ENTER)
    time.sleep(3)
    ans = driver.find_element_by_class_name("answer-box-bd")
    time.sleep(2)
    ansList = ans.find_element_by_class_name("vertList").find_element_by_tag_name("li")
    time.sleep(2)
    ansFinal = ansList.find_element_by_tag_name("input")
    time.sleep(2)
    temp = ansFinal.get_attribute('value')
    time.sleep(2)
    anss.append(temp)
    print("Answer:", temp)

for i in range(len(res)):
    print(f" Question: {res[i].strip()}")
    print("Answer:", anss[i])