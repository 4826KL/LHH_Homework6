#include"Sort.h"

void sortMethod::insertSort(vector<int>&nums)
{
	for (int i = 1; i < nums.size(); i++) {
		//��ԭ����Ҫд��if�е���������forѭ������
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
			swap(nums[j], nums[j - 1]);
		}
	}
}

void sortMethod::BubbleSort(vector<int>& nums)
{
	int n = nums.size();
	bool sorted = false; //�����ж��Ƿ���������ı�־

	for (int i = n -1; i >= 0 && (!sorted); --i)
	{
		sorted = true;
		for (int j = 0; j < i; ++j)
		{
			if (nums[j + 1] < nums[j])
			{
				sorted = false;
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}



//�ϲ�������������
void merge(std::vector<int>& vi, int start, int mid, int end)
{
	//ע��vi[start:mid] �� vi[mid+1], end]�Ѿ����������
	//���俽������������Ŀռ�
	std::vector<int> leftSubArray(vi.begin() + start, vi.begin() + mid + 1);
	std::vector<int> rightSubArray(vi.begin() + mid + 1, vi.begin() + end + 1);

	//˫ָ�뷢��vi.[start, end]�����������
	int leftIndex = 0;
	int rightIndex = 0;

	leftSubArray.insert(leftSubArray.end(), INT_MAX);
	rightSubArray.insert(rightSubArray.end(), INT_MAX);

	for (int i = start; i <= end; ++i)
	{
		if (leftSubArray[leftIndex] < rightSubArray[rightIndex])
		{
			vi[i] = leftSubArray[leftIndex];
			leftIndex++;
		}
		else
		{
			vi[i] = rightSubArray[rightIndex];
			rightIndex++;
		}
	}

}

//�鲢����
void sortMethod::MergeSort(vector<int>& vi, int start, int end)
{
	//��ʣ��һ������ʱ���ݹ����
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(vi, start, mid);
	MergeSort(vi, mid + 1, end);
	merge(vi, start, mid, end);
}

void sortMethod::QuickSort(vector<int>& nums, int l, int r)
{
	if (l >= r) {
		return;
	}
	int i = l, j = r;
	int base = nums[l];  //��׼ֵ

	//��������������һ����baseС��ֵ
	while (i < j) {
		while (nums[j] >= base && i < j) {
			--j;
		}
		//��������������һ����base���ֵ
		while (nums[i] <= base && i < j) {
			++i;
		}
		swap(nums[i], nums[j]); //����base���м�λ�õ���
	}

	swap(nums[l], nums[j]);    // ����base���м�λ�õ���

	QuickSort(nums, l, i - 1);
	QuickSort(nums, i + 1, r);

}

void sortMethod::SelectSort(vector<int>& nums, int start)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int minValueIndex = i;
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[j] < nums[minValueIndex])
				minValueIndex = j;
		}
		swap(nums[minValueIndex], nums[i]);
	}
	
}

void sortMethod::ShellSort(vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1)
		return;

	// ����һ������gap, һ���ʼֵ����Ϊlen/2, Ȼ����С��ʽΪgap/2, ֱ��gap����1ת��Ϊ��������
	int gap = len / 2;
	while (gap >= 1) {
		//�����ݷֳ�gap�飬Ȼ��ÿ���ڽ��в�������
		for (int i = gap; i < len; ++i)
		{
			int insertValue = nums[i];
			int j = i - gap;
			while (j >= 0 && nums[j] > insertValue)
			{
				nums[j + gap] = nums[j];
				j -= gap;
			}
			nums[j + gap] = insertValue;
		}
		gap /= 2;
	}

}

// �ݹ鷽ʽ������ȫ�������ĸ��ڵ�, ʹ����ϴ��������
// start��end�����˶ѵ�������vi�е��±�
void maxHeapify(std::vector<int>& vi, int start, int end)
{
	//��������ӽ���±�
	int left = 2 * start + 1;
	int right = left + 1;

	//���{vi[start], vi[left], vi[right]}���������ֵ�±�
	int maxIndex = start;
	if (left <= end && vi[left] > vi[maxIndex])
		maxIndex = left;
	if (right <= end && vi[right] > vi[maxIndex])
		maxIndex = right;

	//������ڵ㲻�����ѣ��������ӽ���������ݹ������һ��
	if (maxIndex != start)
	{
		std::swap(vi[maxIndex], vi[start]);
		maxHeapify(vi, maxIndex, end);
	}

}
//������
void sortMethod::HeapSort(vector<int>& vi)
{
	// ��ʼ������: �����һ��Ҷ�ӽ�㿪ʼ, ���ҵ�����µ��ϵ����������ɴ����
	for (int i = vi.size() / 2 - 1; i >= 0; --i)
	{
		maxHeapify(vi, i, vi.size() - 1);
	}

	//�����򣺼�����λԪ�غ�������ڵ�ʹ����ϴ��������
	for (int i = vi.size() - 1; i >= 1; --i)
	{
		std::swap(vi[0], vi[i]);
		maxHeapify(vi, 0, i - 1);
	}
}

void sortMethod::CountSort(std::vector<int>& vi)
{
	if (vi.size() <= 1)
		return;

	//�ҵ����ֵ����Сֵ
	int max = vi[0];
	int min = vi[0];

	for (int i : vi)
	{
		max = std::max(i, max);
		min = std::min(i, min);
	}
	if (max == min)
		return;

	//����һ������洢ÿ�����ֻ�����Ӧ�������±�0 ��value��ʾ��ĳ��ִ���
	const int sz = max - min + 1;  //���鳤��
	vector<int> cnt(sz, 0);        //��ʼ��vectorȫΪ0
	for (auto i : vi)
		cnt[i - min] += 1;

	//�޸Ĵ��������
	int index = 0;
	for (int i = 0; i < cnt.size(); ++i)
	{
		int cnti = cnt[i];
		while (cnti)
		{
			vi[index] = i + min;
			index++;
			cnti--;
		}
	}
}
	

void printVector(const std::vector<int>& vi) {
	for (auto i : vi)
		std::cout << " " << i;
	std::cout << std::endl;
}

void sortMethod::SortTest()
{
	//����vector���Ԫ��
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(test_arr), std::end(test_arr), rng);

	vector<int> t = this->test_arr;
	int size = t.size();
	cout << "Qrigin Array Before Sort: ";
	printVector(t);
	
	cout << "Insert Sort Test:";
	insertSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Bubble Sort Test: ";
	BubbleSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Merge Sort Test:";
	MergeSort(t, 0, size - 1);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Quick Sort Test:";
	QuickSort(t, 0, size - 1);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Select Sort Test:";
	SelectSort(t, 0);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Shell Sort Test:";
	ShellSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Heap Sort Test:";
	HeapSort(t);
	printVector(t);
	cout << endl;


	t = this->test_arr;
	cout << "Qrigin Array Before Sort: ";
	printVector(t);

	cout << "Count Sort Test:";
	CountSort(t);
	printVector(t);
	cout << endl;

}



int main()
{
	sortMethod s;
	s.SortTest();
	return 0;
}






