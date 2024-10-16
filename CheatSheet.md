# Cheatsheet: Website Deployment

## Step 1: Choose a Hosting Service
Pick a platform to host your website:
- **GitHub Pages**: For static websites.
- **Netlify**: Easy, free for basic sites.
- **Vercel**: Best for React/Next.js apps.
- **Heroku**: For dynamic websites with backend.

---

## Step 2: Prepare Your Project
- Ensure all your website files (HTML, CSS, JS) are in a folder.
- For dynamic websites, push your project to GitHub or any version control system.

---

## Step 3: Deploy on GitHub Pages (Static Sites)
1. **Push your code** to a GitHub repository.
2. **Enable GitHub Pages**:
   - Go to **Settings** > **Pages**.
   - Select branch (usually "main").
   - Site live at: `https://<username>.github.io/<repo-name>`.

---

## Step 4: Deploy on Netlify (Static Sites)
1. **Sign up** on [Netlify](https://www.netlify.com).
2. **Drag & Drop** site folder or connect GitHub repo.
3. **Custom Domain** (optional): Use free Netlify domain or connect your own.

---

## Step 5: Deploy on Vercel (Static or React/Next.js Sites)
1. **Sign up** on [Vercel](https://vercel.com).
2. **Import project** from GitHub/GitLab.
3. **Automatic Deployment** on every repository push.

---

## Step 6: Deploy on Heroku (Dynamic Sites)
1. **Sign up** on [Heroku](https://www.heroku.com).
2. **Install Heroku CLI**.
3. **Push project to Heroku**:
   - Run `heroku create`.
   - Push code with `git push heroku main`.
   - Site live at: `https://<app-name>.herokuapp.com`.

---

## Step 7: Share Your Website
Once deployed, grab the link and share!

---
