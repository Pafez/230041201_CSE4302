#include <iostream>

using namespace std;

class SocialPost
{
private:
    string postID;
    int totalLikes;
    int totalShares;
public:
    SocialPost() {
        postID = "N/A";
        totalLikes = 0;
        totalShares = 0;
    }
    SocialPost(string PID, int likes, int shares) {
        postID = PID;
        totalLikes = likes;
        totalShares = shares;
        if (totalLikes < 0) totalLikes = 0;
        if (totalShares < 0) totalShares = 0;
    }
    ~SocialPost() {}

    string get_postID() const {
        return postID;
    }
    int get_totalLikes() const {
        return totalLikes;
    }
    int get_totalShares() const {
        return totalShares;
    }

    void set_postID(string PID) {
        postID = PID;
    }
    void set_totalLikes(int likes) {
        totalLikes = likes;
        if (totalLikes < 0) totalLikes = 0;
    }
    void set_totalShares(int shares) {
        totalShares = shares;
        if (totalShares < 0) totalShares = 0;
    }

    void operator+=(int newLikes) {
        totalLikes += newLikes;
    }
    void operator-=(int newUnlikes) {
        totalLikes -= newUnlikes;
        if (totalLikes < 0) totalLikes = 0;
    }
    bool operator==(const SocialPost & other) const {
        return (totalLikes+totalShares)==(other.totalLikes+other.totalShares);
    }
    bool operator>(const SocialPost & other) const {
        return (totalLikes+totalShares*3)>(other.totalLikes+other.totalShares*3);
    }
    bool operator<(const SocialPost & other) const {
        return (totalLikes+totalShares*3)<(other.totalLikes+other.totalShares*3);
    }
};

int main() {
    SocialPost newPost;
    cout << newPost.get_totalLikes() << " ";
    newPost += 7;
    cout << newPost.get_totalLikes() << " ";
    
    return 0;
}
