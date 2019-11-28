#include <array>
#include <unordered_map>
namespace solvant {
namespace sparse {
//! This sparse structure is great for incremental creation
//! of a sparse matrix, but aweful for calculations.
//! DOK = Dictionary Of Keys.
template <typename T>
class DOK_matrix {
    using index_pair = std::pair<std::size_t, std::size_t>;

public:
    DOK_matrix() {}
    void add_entry(std::size_t r, std::size_t c, T& v) {
        auto ind = std::make_pair(r, c);
        m_data[ind] = v;
    }

private:
    // specified hash does not meet the requirements
    std::unordered_map<index_pair, T> m_data;
};
}  // namespace base
}  // namespace solvant
