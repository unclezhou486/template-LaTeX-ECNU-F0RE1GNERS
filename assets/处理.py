import pandas as pd

# 加载Excel文件中的Sheet3
df = pd.read_excel('做题记录.xlsx', sheet_name='Sheet3')

# 转换为Markdown格式并输出
markdown_table = '| 时间 | 比赛 | 比赛地址 | 是否补完 |\n|:--:|:--:|:--------:|:------:|\n'
for index, row in df.iterrows():
    time = row['时间']
    competition = row['比赛']
    url = row['比赛地址']
    completed = row['是否补完'] or ''
    markdown_table += f' ## [{competition}]({url})\n \n --- \n \n'

print(markdown_table)