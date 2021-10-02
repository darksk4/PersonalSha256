#include "SecureHashAlgorithm.hpp"

SecureHashAlgorithm::SecureHashAlgorithm(std::string words)
{
    std::string message = [words]()
    {
        std::string answer = "";
        for(auto& item: words)
            answer += std::bitset<8>(item).to_string();
        return answer;
    }();

    std::vector<std::string> blocks = [message]()
    {
        std::vector<std::string> temp;
        temp.emplace_back("");

        unsigned int iterator = 0;
        for (auto& item : message)
        {
            temp.back() += item;
            if (++iterator == 440)
            {
                temp.emplace_back("");
                iterator = 0;
            }
        }
        return temp;
    }();

    std::transform(blocks.begin(), blocks.end(), blocks.begin(),
        [](std::string binary) -> std::string {
            int size = binary.size();
            if (size == 0)
                return {};
            std::string binarySize = std::bitset<64>(size).to_string();

            binary += '1';

            binary.insert(binary.size(), 448 - binary.size(), '0');
            binary += binarySize;
            return binary;
        });

    auto it = std::remove_if(blocks.begin(), blocks.end(),
        [](std::string binary) -> bool {
            if (binary.empty())
                return true;
            return false;
        });
    blocks.erase(it, blocks.end());
    compression = new Compression(blocks);
}

std::string SecureHashAlgorithm::toString()
{
    if (compression == NULL)
        return std::string {};
    return compression->toString();
}
