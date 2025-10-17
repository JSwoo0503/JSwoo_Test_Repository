import sys
import pandas as pd

def csv_to_html(csv_file, html_file):
    # CSV 읽기
    df = pd.read_csv(csv_file)

    # HTML 변환 (스타일 추가)
    html_content = f"""
    <html>
    <head>
        <meta charset="utf-8">
        <title>{csv_file} Report</title>
        <style>
            body {{
                font-family: Arial, sans-serif;
                margin: 20px;
            }}
            h2 {{
                color: #333;
            }}
            table {{
                border-collapse: collapse;
                width: 100%;
                margin-top: 10px;
            }}
            th, td {{
                border: 1px solid #ccc;
                padding: 8px;
                text-align: left;
            }}
            th {{
                background-color: #f2f2f2;
            }}
            tr:nth-child(even) {{
                background-color: #fafafa;
            }}
        </style>
    </head>
    <body>
        <h2>Analysis Report: {csv_file}</h2>
        {df.to_html(index=False, escape=False)}
    </body>
    </html>
    """

    # HTML 저장
    with open(html_file, "w", encoding="utf-8") as f:
        f.write(html_content)

    print(f"[INFO] HTML report generated: {html_file}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python csv_to_html.py <input.csv> <output.html>")
        sys.exit(1)

    csv_file = sys.argv[1]
    html_file = sys.argv[2]
    csv_to_html(csv_file, html_file)
