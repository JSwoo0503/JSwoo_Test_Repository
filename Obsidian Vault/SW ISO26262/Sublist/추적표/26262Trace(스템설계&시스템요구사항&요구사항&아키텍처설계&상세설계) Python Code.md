import re

import csv

  

def parse_and_save_all_relations(input_file):

    """

    텍스트 파일에서 다양한 요구사항 및 컴포넌트 관계를 파싱하여

    각 관계별로 별도의 CSV 파일로 저장합니다.

    """

    try:

        with open(input_file, 'r', encoding='utf-8') as f:

            content = f.read()

    except FileNotFoundError:

        print(f"오류: '{input_file}' 파일을 찾을 수 없습니다. 파일을 확인해주세요.")

        return

  

    # 각 항목을 저장할 리스트

    pde_list = []

    tr_list = []

    tsr_list = []

    tsc_list = []

    swc_sr_list = []

    swc_swu_list = []

    sci_sui_list = []

    # SUI/SWF ID와 관련된 SR/SNR/SSR ID를 저장할 리스트

    sui_sf_sr_list = []

  

    # SUI-xxx 또는 SWF-xxx ID와 "Related Req. ID"를 함께 찾는 정규 표현식

    # 이 패턴은 여러 줄에 걸쳐 있을 수 있는 "Related Req. ID"를 처리하기 위해

    # non-greedy (.*?)와 re.DOTALL을 사용합니다.

    # [] 안에 SUI- 또는 SWF-로 시작하는 텍스트를 찾고, 그 이후 'Related Req. ID' 필드의 값을 찾습니다.

    sui_sf_sr_pattern = re.compile(

        r'\[(SUI-\w+-\d+|SWF-\w+-\d+)\].*?Related Req\. ID\s*([^\r\n]+)',

        re.DOTALL

    )

  

    # 패턴을 사용하여 모든 매치를 찾습니다.

    sui_sf_sr_matches = sui_sf_sr_pattern.findall(content)

  

    for sui_sf_sr_match in sui_sf_sr_matches:

        req_id = sui_sf_sr_match[0].strip()

        related_ids_str = sui_sf_sr_match[1].strip()

  

        # Related Req. ID가 여러 개일 경우 쉼표로 분리

        related_ids = [s.strip() for s in related_ids_str.split(',') if s.strip()]

  

        # 각 요구사항 ID와 관련 요구사항 ID 쌍을 리스트에 추가합니다.

        for related_id in related_ids:

            sui_sf_sr_list.append([req_id, related_id])

    # SCI 블록과 SUI 블록을 모두 찾습니다.

    # 각 블록에서 ID와 함수 이름을 추출합니다.

    sci_pattern = r'\[(SCI-\w+-\d+)\]\s*(\w+\(\))'

    sui_pattern = r'\[(SUI-\w+-\d+)\]\s*(\w+\(\))'

    sci_matches = re.findall(sci_pattern, content)

    sui_matches = re.findall(sui_pattern, content)

  

    sci_data = {func.strip(): sci_id.strip() for sci_id, func in sci_matches}

    sui_data = {func.strip(): sui_id.strip() for sui_id, func in sui_matches}

  

    # 함수 이름이 동일한 SCI와 SUI를 매칭합니다.

    for func, sci_id in sci_data.items():

        if func in sui_data:

            sui_id = sui_data[func]

            sci_sui_list.append([sci_id, sui_id])

  

    # SWC와 SWU의 중간 코드를 비교하여 매칭합니다.

    swc_pattern = r'\[(SWC-\w+-\d+)\]'

    swu_pattern = r'\[(SWU-\w+-\d+)\]'

    swcs = re.findall(swc_pattern, content)

    swus = re.findall(swu_pattern, content)

    for swc in swcs:

        swc_mid_code = swc.split('-')[1]

        for swu in swus:

            swu_mid_code = swu.split('-')[1]

            if swc_mid_code == swu_mid_code:

                swc_swu_list.append([swc, swu])

  

    # 요구사항 블록을 분리하는 정규 표현식

    sr_block_pattern = r'(\[\w+-\w+-\w+-\d+\](?:.|\n)*?)(?=\[\w+-\w+-\w+-\d+\]|\Z)'

    sr_blocks = re.findall(sr_block_pattern, content)

  

    for block in sr_blocks:

        # 각 블록에서 필요한 항목들을 추출합니다.

        sr_id_match = re.search(r'요구사항 식별자\s*(.*?)\n', block)

        pde_id_match = re.search(r'관련 시스템 엘리먼트\s*(.*?)\n', block)

        tr_id_match = re.search(r'관련 시스템 요구사항\s*(.*?)\n', block)

        tsr_id_match = re.search(r'관련 요구사항\s*(.*?)\n', block)

        tsc_id_match = re.search(r'관련 TSC\s*(.*?)\n', block)

  

        sr_id = sr_id_match.group(1).strip() if sr_id_match else "없음"

  

        pde_ids = [s.strip() for s in pde_id_match.group(1).strip().split(',')] if pde_id_match else []

        tr_ids = [s.strip() for s in tr_id_match.group(1).strip().split(',')] if tr_id_match else []

        tsr_ids = [s.strip() for s in tsr_id_match.group(1).strip().split(',')] if tsr_id_match else []

        tsc_ids = [s.strip() for s in tsc_id_match.group(1).strip().split(',')] if tsc_id_match else []

        # 각 리스트에 데이터 추가

        for pde_id in pde_ids:

            if pde_id: pde_list.append([sr_id, pde_id])

        for tr_id in tr_ids:

            if tr_id: tr_list.append([sr_id, tr_id])

        for tsr_id in tsr_ids:

            if tsr_id: tsr_list.append([sr_id, tsr_id])

        for tsc_id in tsc_ids:

            if tsc_id: tsc_list.append([sr_id, tsc_id])

  

    # SWC 블록을 분리하는 정규 표현식

    swc_block_pattern = r'(\[SWC-\w+-\d+\](?:.|\n)*?)(?=\[SWC-\w+-\d+\]|\Z)'

    swc_blocks = re.findall(swc_block_pattern, content)

  

    for block in swc_blocks:

        swc_id_match = re.search(r'\[(SWC-\w+-\d+)\]', block)

        sr_ids_match = re.search(r'관련 요구사항\s*(.*?)\n', block)

  

        if swc_id_match and sr_ids_match:

            swc_id = swc_id_match.group(1).strip()

            sr_ids = [s.strip() for s in sr_ids_match.group(1).strip().split(',')]

            for sr_id in sr_ids:

                if sr_id:

                    swc_sr_list.append([swc_id, sr_id])

    # 별도의 CSV 파일로 저장하는 헬퍼 함수

    def save_to_csv(filename, header, data_list):

        with open(filename, 'w', newline='', encoding='utf-8-sig') as f:

            writer = csv.writer(f)

            writer.writerow(header)

            writer.writerows(data_list)

            print(f"'{filename}' 파일이 성공적으로 저장되었습니다.")

  

    # 각 리스트를 CSV 파일로 저장

    save_to_csv('pde-srssr.csv', ["요구사항_식별자", "관련_시스템_엘리먼트"], pde_list)

    save_to_csv('tr-sr.csv', ["요구사항_식별자", "관련_시스템_요구사항"], tr_list)

    save_to_csv('tsr-ssr.csv', ["요구사항_식별자", "관련_테스트_요구사항"], tsr_list)

    save_to_csv('tsc-ssr.csv', ["요구사항_식별자", "관련_테스트_케이스"], tsc_list)

    save_to_csv('swc-sr.csv', ["SWC", "관련_요구사항"], swc_sr_list)

    save_to_csv('swc-swu.csv', ["SWC", "SWU"], swc_swu_list)

    save_to_csv('sci-sui.csv', ["SCI", "SUI"], sci_sui_list)

    save_to_csv('sui-sr.csv', ["요구사항 ID", "관련 요구사항 ID"], sui_sf_sr_list)

  

# 실행

parse_and_save_all_relations('input.txt')